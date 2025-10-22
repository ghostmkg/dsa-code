// queue_using_stacks.cpp
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    cout << "Front element: " << q.peek() << endl;
    cout << q.pop() << " dequeued\n";
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}
