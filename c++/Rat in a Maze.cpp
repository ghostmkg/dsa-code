class Solution {
  public:
    
    int n,m;
    vector<string>result;
    
    
    void solve(vector<vector<int>>& maze, int i, int j, string &temp,vector<vector<bool>>&visited){
           if (i>=n || j>=n || i<0 || j<0 ||  maze[i][j]==0 || visited[i][j]) {
                
                   return ;
           }
           if (i==n-1 && j ==m-1) {
                 result.push_back(temp);
                 
                 return ;
           }
          
           visited[i][j]=true;
           temp.push_back('D');
           solve(maze , i+1,j,temp , visited);
           temp.pop_back();
            temp.push_back('R');
           solve(maze , i,j+1,temp ,visited);
               temp.pop_back();
               temp.push_back('U');
           solve(maze , i-1,j,temp,visited);
               temp.pop_back();
               temp.push_back('L');
           solve(maze , i,j-1,temp, visited);
               temp.pop_back();
              visited[i][j]=false;
          
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        n= maze.size();
        m= maze[0].size();
        string temp = "";
          if (maze[0][0] == 0) {
            return {}; // Return an empty vector immediately
        }
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        solve(maze,0,0,temp,visited);
        sort(result.begin(),result.end());
        return result;
        
    }
};
