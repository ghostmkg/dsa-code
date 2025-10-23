#include <string>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9x9 array
        string row,col,box;
       unordered_set<string>st;
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;
            
        
// tino(3) main ek string object banayenge
// main purpose har i , j , i& j ko string main convert karna
// ye tion(3) condition string main convert karke set main save hojaengi
        row=string(1,board[i][j]) + "_ROW_" + to_string(i);
        col=string(1,board[i][j]) + "_Col_" + to_string(j);
        box=string(1,board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

// agar st ka element dubara milgya tou fALSE
// agr row vala jo aaya vo dekh rakha hai pehle
if(st.find(row)!=st.end() || st.find(col)!=st.end()||st.find(box)!=st.end())
return false;
st.insert(row);
st.insert(col);
st.insert(box);
}}
/* agr if condition false nahi hai tou aesa kahi bhi nahi hua hAI KI DUplicate aaya ho matlab saare 
unique honge uss case main */

// poora insertion karke check karke fale ka agar 
// unique aaraha hai 9x9 mat tou true hai
return true;
           
    }
};