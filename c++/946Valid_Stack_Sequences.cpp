class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        stack<int>st;
        int m=pushed.size();
        int n=popped.size();
        while(i<m )
         {  st.push(pushed[i]);
            i++;
            while(!st.empty() && popped[j]==st.top())
            {
                st.pop();
                j++;
            }
         }
        

        
        return st.empty();
    }
};