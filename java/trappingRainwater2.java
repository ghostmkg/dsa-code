import java.util.*;

public class trappingRainwater2 {
    // Helper class to store cell information
    private class Entry {
        int h, i, j;
        Entry(int h, int i, int j){
            this.h = h;
            this.i = i;
            this.j = j;
        }
    }

    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length == 0 || heightMap[0].length == 0) {
            return 0;
        }

        int rows = heightMap.length;
        int cols = heightMap[0].length;

        PriorityQueue<Entry> queue = new PriorityQueue<>((a, b) -> a.h - b.h);
        boolean[][] visited = new boolean[rows][cols];

        // directions: left, right, up, down
        int[][] directions = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };

        // Step 1: Add all boundary cells to heap
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (isOnBoundary(i, j, rows, cols)) {
                    queue.offer(new Entry(heightMap[i][j], i, j));
                    visited[i][j] = true;
                }
            }
        }

        int maxValue = 0;  // tracks highest boundary seen so far
        int trapWater = 0; // result

        // Step 2: Process heap
        while (!queue.isEmpty()) {
            Entry entry = queue.poll();
            maxValue = Math.max(maxValue, entry.h);

            for (int[] dir : directions) {
                int newX = entry.i + dir[0];
                int newY = entry.j + dir[1];

                if (isValid(newX, newY, rows, cols) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    int currentHeight = heightMap[newX][newY];

                    // if current cell lower than water level, water can be trapped
                    if (currentHeight < maxValue) {
                        trapWater += (maxValue - currentHeight);
                    }

                    // push neighbor with its original height
                    queue.offer(new Entry(currentHeight, newX, newY));
                }
            }
        }
        return trapWater;
    }

    // check if coordinates are inside grid
    private boolean isValid(int x, int y, int rows, int cols){
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }

    // check if cell is on boundary
    private boolean isOnBoundary(int i, int j, int rows, int cols){
        return i == 0 || j == 0 || i == rows - 1 || j == cols - 1;
    }

    // Main function for testing
    public static void main(String[] args) {
        trappingRainwater2 sol = new trappingRainwater2();
        int[][] heightMap = {
            {1,4,3,1,3,2},
            {3,2,1,3,2,4},
            {2,3,3,2,3,1}
        };

        System.out.println(sol.trapRainWater(heightMap)); 
        // Expected output: 4
    }
}
