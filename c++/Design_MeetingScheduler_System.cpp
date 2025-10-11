💡 Question: MeetingScheduler System

You are asked to design a MeetingScheduler system that manages meeting requests between users.
Each meeting has a start time, end time, and priority (higher = more important).

The system should support efficient scheduling, editing, and execution of meetings.

Implement the MeetingScheduler class:
Constructor:
MeetingScheduler(vector<vector<int>>& meetings)


Initializes the meeting scheduler with a list of existing meetings.
Each meeting is represented as [meetingId, startTime, endTime, priority].

Methods:
void add(int meetingId, int startTime, int endTime, int priority)


Adds a new meeting with given details.
It is guaranteed that meetingId is unique.

void edit(int meetingId, int newStart, int newEnd, int newPriority)


Edits an existing meeting's details.
It is guaranteed that meetingId exists.

void rmv(int meetingId)


Removes the meeting with the given ID.
It is guaranteed that meetingId exists.

int execTop()


Executes (starts) the meeting with the highest priority.
If multiple meetings share the same priority, choose the one with earliest start time.
Once executed, the meeting is removed from the system.
Return the meetingId of the executed meeting.
If no meetings are available, return -1.

Example

Input:

["MeetingScheduler", "add", "edit", "execTop", "rmv", "add", "execTop"]
[[[[1, 9, 10, 5], [2, 14, 15, 8], [3, 16, 17, 7]]], [4, 11, 12, 10], [3, 10, 11, 12], [], [1], [5, 18, 19, 6], []]


Output:

[null, null, null, 3, null, null, 4]


Explanation:

MeetingScheduler scheduler({
  {1, 9, 10, 5}, 
  {2, 14, 15, 8}, 
  {3, 16, 17, 7}
});
scheduler.add(4, 11, 12, 10);   // Adds meeting 4 with highest priority
scheduler.edit(3, 10, 11, 12);  // Updates meeting 3 to priority 12
scheduler.execTop();             // Executes meeting 3 (highest priority 12)
scheduler.rmv(1);                // Removes meeting 1
scheduler.add(5, 18, 19, 6);     // Adds meeting 5
scheduler.execTop();             // Executes meeting 4 (next highest 10)

Constraints

1 <= meetings.length <= 10^5

0 <= meetingId, startTime, endTime <= 10^5

0 <= priority <= 10^9

Up to 2 * 10^5 total calls will be made to add, edit, rmv, and execTop.

✅ Solution (C++ - Efficient using Maps + Sets)
#include <bits/stdc++.h>
using namespace std;

class MeetingScheduler {
public:
    // priority -> set of {startTime, meetingId, endTime}
    map<int, set<tuple<int, int, int>>> meetings; 
    unordered_map<int, tuple<int, int, int>> info; // meetingId -> {start, end, priority}

    MeetingScheduler(vector<vector<int>>& initMeetings) {
        for (auto &m : initMeetings)
            add(m[0], m[1], m[2], m[3]);
    }

    void add(int meetingId, int start, int end, int priority) {
        meetings[priority].insert({start, meetingId, end});
        info[meetingId] = {start, end, priority};
    }

    void edit(int meetingId, int newStart, int newEnd, int newPriority) {
        auto [oldStart, oldEnd, oldPriority] = info[meetingId];
        meetings[oldPriority].erase({oldStart, meetingId, oldEnd});
        if (meetings[oldPriority].empty())
            meetings.erase(oldPriority);

        add(meetingId, newStart, newEnd, newPriority);
    }

    void rmv(int meetingId) {
        auto [start, end, priority] = info[meetingId];
        meetings[priority].erase({start, meetingId, end});
        if (meetings[priority].empty())
            meetings.erase(priority);
        info.erase(meetingId);
    }

    int execTop() {
        if (meetings.empty()) return -1;

        auto last = prev(meetings.end()); // highest priority
        auto &setRef = last->second;
        auto top = *setRef.begin();       // earliest start time among highest priority

        int start = get<0>(top);
        int meetingId = get<1>(top);
        int end = get<2>(top);
        int priority = last->first;

        setRef.erase(top);
        if (setRef.empty()) meetings.erase(priority);
        info.erase(meetingId);

        return meetingId;
    }
};

🧠 Concepts Demonstrated

Map + Set combo: Efficient O(log N) insert/delete and retrieval.

Tuple comparison: Allows natural ordering by (startTime, meetingId).

Clean design principles: Clear data separation between fast access (unordered_map) and sorted access (map).
