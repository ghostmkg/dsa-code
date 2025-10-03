import java.util.*;

public class TrappingRainWaterII {
    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length == 0 || heightMap[0].length == 0) {
            return 0;
        }

        int m = heightMap.length;
        int n = heightMap[0].length;

        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        for (int i = 0; i < m; i++) {
            pq.offer(new int[]{i, 0, heightMap[i][0]});
            pq.offer(new int[]{i, n - 1, heightMap[i][n - 1]});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.offer(new int[]{0, j, heightMap[0][j]});
            pq.offer(new int[]{m - 1, j, heightMap[m - 1][j]});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

    
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int waterTrapped = 0;

        while (!pq.isEmpty()) {
            int[] cell = pq.poll();
            int x = cell[0], y = cell[1], height = cell[2];

            for (int[] d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    waterTrapped += Math.max(0, height - heightMap[nx][ny]);
                    pq.offer(new int[]{nx, ny, Math.max(heightMap[nx][ny], height)});
                }
            }
        }

        return waterTrapped;
    }
    public static void main(String[] args) {
        TrappingRainWaterII solver = new TrappingRainWaterII();

        int[][] heightMap1 = {
            {1,4,3,1,3,2},
            {3,2,1,3,2,4},
            {2,3,3,2,3,1}
        };
        System.out.println("Output 1: " + solver.trapRainWater(heightMap1)); 

        int[][] heightMap2 = {
            {3,3,3,3,3},
            {3,2,2,2,3},
            {3,2,1,2,3},
            {3,2,2,2,3},
            {3,3,3,3,3}
        };
        System.out.println("Output 2: " + solver.trapRainWater(heightMap2)); 
    }
}
