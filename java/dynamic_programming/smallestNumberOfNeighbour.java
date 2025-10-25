//  Find the City With the Smallest Number of Neighbors at a Threshold Distance


// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.




class smallestNumberOfNeighbour {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {

        int INF = 10001;
        int [][] dist = new int[n][n];

        for(int i=0;i<n ; i++){
            for(int j=0;j<n;j++){
                dist[i][j] = (i==j) ? 0 : INF;
            }
        }

        for(int []edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;

        
        }

        for(int k =0 ; k<n ; k++){
            for(int i = 0 ; i<n ; i++){
                for(int j=0; j<n ; j++){
                 if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
  int resultCity = -1;
        int minReachable = n;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // Tie-breaker: prefer larger city index
            if (count <= minReachable) {
                minReachable = count;
                resultCity = i;
            }
        }

        return resultCity;

        
    }

    public static void main(String[] args) {
        smallestNumberOfNeighbour solution = new smallestNumberOfNeighbour();

        int n1 = 4;
        int[][] edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
        int distanceThreshold1 = 4;
        System.out.println(solution.findTheCity(n1, edges1, distanceThreshold1));

        int n2 = 5;
        int[][] edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
        int distanceThreshold2 = 2;
        System.out.println(solution.findTheCity(n2, edges2, distanceThreshold2)); 
    }
}
 