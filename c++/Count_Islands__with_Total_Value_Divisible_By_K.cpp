class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<bool>> visited(m,vector<bool> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<i<<" "<<j<<" "<<visited[i][j]<<'\n';
                if(!(visited[i][j])&&grid[i][j]>0){
                    long long sum=0;
                    int a=i;
                    int b=j;
                    dfs(grid,visited,a,b,sum,m,n);
                    //cout<<sum<<" "<<grid[i][j]<<" "<<i<<" "<<j<<"\n";
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int &x,int &y, long long &sum, int m, int n){
        sum+=grid[x][y];
        //cout<<grid[x][y]<<" "<<x<<" "<<y<<" ";
        visited[x][y]=true;
        if(x<m-1){
           int l=x+1;
           if(grid[l][y]!=0&&!visited[l][y])
            dfs(grid,visited,l,y,sum,m,n);
        }
        if(y<n-1){
            int h=y+1;
            if(grid[x][h]!=0&&!visited[x][h])
            dfs(grid,visited,x,h,sum,m,n);
        }
        if(x>0){
            int a=x-1;
            if(grid[a][y]>0 &&!visited[a][y])
             dfs(grid,visited,a,y,sum,m,n);
        }
        if(y>0){
            int b=y-1;
            if(grid[x][b]>0 &&!visited[x][b])
            dfs(grid,visited,x,b,sum,m,n);
        }
       
    }

};