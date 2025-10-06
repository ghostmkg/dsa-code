class Solution {
    public int uniquePathsWithObstacles(int[][] og) {
        int m = og.length, n = og[0].length;
        int[][] ans = new int[m][n];

        for(int i=0; i<m; i++){
            if(og[i][0] == 1){
                ans[i][0] = 0;
                break;
            }
            else{
                ans[i][0] = 1;
            }
        }

        for(int j=0; j<n; j++){
            if(og[0][j] == 1){
                ans[0][j] = 0;
                break;
            }
            else{
                ans[0][j] = 1;
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(og[i][j] == 1){
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
            }

        }
        
        return ans[m-1][n-1];
    }
}