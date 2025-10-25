

// Unique Paths II

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109.


class UniquePathsii{
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n= obstacleGrid[0].length;


        int dp[][] = new int[m][n];

    //     for(int i = 0 ; i<m ;i++){
    //         Arrays.fill(dp[i],-1);
    //     }
    
    //    return mazememo(m-1,n-1,obstacleGrid, dp );

    return tabulation(obstacleGrid);

    
        
    }
    public int mazememo(int i, int j, int [][] obstacleGRid , int dp[][]){
          

        if(i<0 || j<0){
            return  0;
        }

        if((i>=0 && j>=0 ) && obstacleGRid[i][j] ==1){
            return 0;
        }

        if(i==0 && j==0){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = mazememo(i-1,j,obstacleGRid,dp );
        int left = mazememo(i,j-1, obstacleGRid, dp);

         dp[i][j] = up+left;

         return dp[i][j];
    }

    public int tabulation( int[][] obstacleGrid){
            int m = obstacleGrid.length;
         int n= obstacleGrid[0].length;

         int dp[][] = new int[m][n];
         for(int i =0; i<m; i++){
            for(int j =0 ; j<n ; j++){

                if((i==0 && j==0) && obstacleGrid[i][j] != 1 ) dp[i][j] = 1;
                else{

                    int left =0;
                    int up =0;

                    if(obstacleGrid[i][j]==1){
                        dp[i][j] = 0;
                        continue;
                    }

                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                     dp[i][j] = up + left;

                }

            }
         }

         return dp[m-1][n-1];

    }


    public static void main(String[] args) {
        UniquePathsii uniquePathsii = new UniquePathsii();
        int[][] obstacleGrid = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
        };

        System.out.println(uniquePathsii.uniquePathsWithObstacles(obstacleGrid)); 
    }




}