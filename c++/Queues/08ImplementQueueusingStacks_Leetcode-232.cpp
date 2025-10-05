#include <bits/stdc++.h>
using namespace std;
/*class MyQueue {// push efficent
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {//remove at bottom//O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {//O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};*/

class MyQueue {//pop peak efficent
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {//push at bottom
        if(st.size()==0){
        st.push(x);
        return;
    }
    else{
         while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
    }
}
    
    int pop() {//remove at bottom//O(1)
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() {//O(1)
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Peek: " << q.peek() << std::endl; // Output: 1
    std::cout << "Pop: " << q.pop() << std::endl; // Output: 1
    std::cout << "Empty: " << (q.empty() ? "Yes" : "No") << std::endl; // Output: No

    std::cout << "Peek: " << q.peek() << std::endl; // Output: 2
    std::cout << "Pop: " << q.pop() << std::endl; // Output: 2
    std::cout << "Empty: " << (q.empty() ? "Yes" : "No") << std::endl; // Output: No

    std::cout << "Peek: " << q.peek() << std::endl; // Output: 3
    std::cout << "Pop: " << q.pop() << std::endl; // Output: 3
    std::cout << "Empty: " << (q.empty() ? "Yes" : "No") << std::endl; // Output: Yes

    return 0;
}