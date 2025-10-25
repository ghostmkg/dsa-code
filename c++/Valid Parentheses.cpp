#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        return st.empty();
    }
};

int main() {
    Solution obj;
    cout << obj.isValid("()[]{}") << endl; // 1 (true)
    cout << obj.isValid("(]") << endl;     // 0 (false)
}
