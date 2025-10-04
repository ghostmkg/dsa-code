class Solution {
    int ans = 0;
    PriorityQueue<Building> heap;
    public int trapRainWater(int[][] heightMap) {

       this.heap = new PriorityQueue<>(
            (a,b) -> a.height - b.height
        );

        int n = heightMap[0].length;
        int m = heightMap.length;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    heap.add(new Building(i,j,heightMap[i][j]));
                    heightMap[i][j] = -1;
                }
            }
        }

        while(!heap.isEmpty()){
            Building b = heap.poll();
            int i = b.x;
            int j = b.y;
            int maxHeight = b.height;
            dfs(heightMap, i, j + 1, maxHeight);
            dfs(heightMap, i, j - 1, maxHeight);
            dfs(heightMap, i + 1, j, maxHeight);
            dfs(heightMap, i - 1, j, maxHeight);
        }

        return ans;
    }

    public void dfs(int[][] grid, int i, int j, int maxHeight){
        if(i <= 0 || j <= 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == -1)
            return;
        
        if(grid[i][j] >= maxHeight){
            heap.add(new Building(i, j, grid[i][j]));
            grid[i][j] = -1;
        } else { 
            ans += (maxHeight - grid[i][j]);
            grid[i][j] = -1;
            dfs(grid, i, j + 1, maxHeight);
            dfs(grid, i, j - 1, maxHeight);
            dfs(grid, i + 1, j, maxHeight);
            dfs(grid, i - 1, j, maxHeight);
        }
    }
}

class Building{
    int x;
    int y;
    int height;

    public Building(int x, int y, int height){
        this.x = x;
        this.y = y;
        this.height = height;
    }


}
