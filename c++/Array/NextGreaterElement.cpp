#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        result[i] = (st.empty()) ? -1 : st.top();

        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}
