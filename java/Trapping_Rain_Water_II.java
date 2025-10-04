class Solution {

    public int trapRainWater(int[][] heightMap) {
        //left,right,down, up
        int dir[][] = {{0,-1},{0,1},{-1,0},{1,0}};
        int rows = heightMap.length;
        int cols = heightMap[0].length;
        if(rows <3 || cols <3) return 0;
        int totalUnvisitedCells = rows*cols;
        boolean[][] visited = new boolean[rows][cols];
        // [hight, row, col] -> inc order of height
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> (a[0]-b[0]));
        
        for (int i = 0; i < rows; i++) {
            pq.offer(new int[]{heightMap[i][0], i, 0});
            pq.offer(new int[]{heightMap[i][cols - 1], i, cols - 1});
            visited[i][0] = true;
            visited[i][cols - 1] = true;
            totalUnvisitedCells--;
            totalUnvisitedCells--;
        }

        for (int i = 1; i < cols-1; i++) {
            pq.offer(new int[]{heightMap[0][i], 0, i});
            pq.offer(new int []{heightMap[rows - 1][i], rows - 1, i});
            visited[0][i] = true;
            visited[rows - 1][i] = true;
            totalUnvisitedCells--;
            totalUnvisitedCells--;
        }
        int trappedWater = 0;
        int waterLevel=0;
        //n*mlog(n*m)
        while (!pq.isEmpty() && totalUnvisitedCells>0) {
            int currentCell[] = pq.poll();
            int currentHeight = currentCell[0];
            int currentRow = currentCell[1];
            int currentCol = currentCell[2];
            waterLevel = Math.max(waterLevel, currentHeight);
            // Explore all 4 neighboring cells
            for (int direction = 0; direction < 4; direction++) {
                int neighborRow = currentRow + dir[direction][0];
                int neighborCol = currentCol + dir[direction][1];
                // Check if the neighbor is within the grid bounds and not yet visited
                if (isValidCell(neighborRow,neighborCol,rows,cols) && !visited[neighborRow][neighborCol]) {
                    int neighborHeight = heightMap[neighborRow][neighborCol];
                    if (neighborHeight < waterLevel) {
                        trappedWater += waterLevel - neighborHeight;
                    }
                    pq.offer(new int[]{neighborHeight,neighborRow,neighborCol});
                    visited[neighborRow][neighborCol] = true;
                    totalUnvisitedCells--;
                }
            }
        }
        return trappedWater;
    }

    private boolean isValidCell(int row,int col,int rows,int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
}