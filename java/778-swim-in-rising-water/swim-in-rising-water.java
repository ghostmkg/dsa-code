class Solution {
    boolean[][] visited;
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int l = 0; int r = n * n - 1;
        int min = n * n - 1;

        while(l <= r) {
            int mid = l + ((r - l)/2);
            visited = new boolean[n][n];
            if(dfs(grid, mid, 0, 0, n)){
                r = mid - 1;
                min = mid;
            }
            else
                l = mid + 1;
        }
        return min;
    }
    private boolean dfs(int[][] grid, int max_value, int i, int j, int n){
        if(i < 0 || j < 0 || j == n || i == n || visited[i][j] || grid[i][j] > max_value) //break
            return false;
        if(i == n-1 && j == n-1)
            return true;

        visited[i][j] = true;   // mark visited

        boolean right = dfs(grid, max_value, i, j+1, n);
        boolean left = dfs(grid, max_value, i, j-1, n);
        boolean bottom = dfs(grid, max_value, i+1, j, n);
        boolean top = dfs(grid, max_value, i-1, j, n);

        return (right || left || bottom || top) ? true : false;
    }
    
}
