#include <bits/stdc++.h>
using namespace std;
class Solution {//m1
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n=students.size();
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int i=0;//traverse the sandwiches array
        int count=0;
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sandwiches[i]){
                count =0;
                q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};
/*class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int students_count = students.size(), cir = 0, squ = 0;
        for (int i = 0; i < students.size(); i++){
            if (students[i] == 0) cir++;
            else squ++;
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0){
                if (cir > 0){
                    cir--;
                    students_count--;
                }
                else{
                    return students_count;
                }
            }
            else{
                if (squ > 0) {
                    squ--;
                    students_count--;
                }
                else{
                    return students_count;
                }
            }
        }
        return 0;
    }
};*/
int main() {
    Solution solution;

    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = solution.countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}