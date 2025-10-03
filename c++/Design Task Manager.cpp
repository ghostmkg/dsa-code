Question : - 

There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the TaskManager class:

TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.

void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.

void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.

void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.

int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.

Note that a user may be assigned multiple tasks.

 

Example 1:

Input:
["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
[[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]

Output:
[null, null, null, 3, null, null, 5]

Explanation

TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
taskManager.edit(102, 8); // Updates priority of task 102 to 8.
taskManager.execTop(); // return 3. Executes task 103 for User 3.
taskManager.rmv(101); // Removes task 101 from the system.
taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
taskManager.execTop(); // return 5. Executes task 105 for User 5.
 

Constraints:

1 <= tasks.length <= 105
0 <= userId <= 105
0 <= taskId <= 105
0 <= priority <= 109
0 <= newPriority <= 109
At most 2 * 105 calls will be made in total to add, edit, rmv, and execTop methods.
The input is generated such that taskId will be valid.


Solution : - 

#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    map<int, set<pair<int, int>>> mp;   // priority -> set of (taskId, userId)
    unordered_map<int, int> mp2;        // taskId -> priority

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[priority].insert({taskId, userId});
        mp2[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int userId = remove(taskId);
        add(userId, taskId, newPriority);
    }

    int remove(int taskId) {
        if (!mp2.count(taskId)) return -1; // not found

        int prevPriority = mp2[taskId];
        auto &st = mp[prevPriority]; // reference, not copy

        // find the pair and erase
        auto it = find_if(st.begin(), st.end(), [&](auto &p) {
            return p.first == taskId;
        });

        int userId = -1;
        if (it != st.end()) {
            userId = it->second;
            st.erase(it);
        }

        if (st.empty()) mp.erase(prevPriority); // clean up
        mp2.erase(taskId);
        return userId;
    }

    void rmv(int taskId) {
        remove(taskId);
    }

    int execTop() {
        if (mp.empty()) return -1;

        // last element in map = highest priority
        auto last = prev(mp.end());
        auto &st = last->second;

        // highest taskId in this set = rbegin()
        auto it = st.rbegin();
        int taskId = it->first;
        int userId = it->second;

        // erase from set and mp2
        st.erase(--it.base()); // convert reverse_iterator to normal iterator
        if (st.empty()) mp.erase(last);
        mp2.erase(taskId);

        return userId;
    }
};

  
