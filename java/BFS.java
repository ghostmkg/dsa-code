// BFS from given source s
import java.util.*;
import java.util.Queue;
import java.util.LinkedList;

public class BFS {

    static ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        int V = adj.size();
        ArrayList<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[V];
        Queue<Integer> q = new LinkedList<>();

        // Iterate through all vertices to ensure all components are visited
        for (int startNode = 0; startNode < V; startNode++) {
            
            // Start BFS only if the node hasn't been visited (i.e., it's a new component)
            if (!visited[startNode]) {
                // Initialize the BFS for the new component
                visited[startNode] = true;
                q.add(startNode);

                // Standard BFS logic
                while (!q.isEmpty()) {
                    int curr = q.poll();
                    result.add(curr); // Add the current node to the result list

                    // Traverse neighbors
                    for (int neighbor : adj.get(curr)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.add(neighbor);
                        }
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        // Graph from the original example:
        // Component 1: 0, 1, 2
        // Component 2: 3, 4, 5
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        // Node 0: neighbors 1, 2
        adj.add(new ArrayList<>(Arrays.asList(1, 2))); 
        // Node 1: neighbor 0
        adj.add(new ArrayList<>(Arrays.asList(0))); 
        // Node 2: neighbor 0
        adj.add(new ArrayList<>(Arrays.asList(0))); 
        // Node 3: neighbor 4
        adj.add(new ArrayList<>(Arrays.asList(4)));
        // Node 4: neighbors 3, 5
        adj.add(new ArrayList<>(Arrays.asList(3, 5)));
        // Node 5: neighbor 4
        adj.add(new ArrayList<>(Arrays.asList(4))); 

        ArrayList<Integer> ans = bfs(adj);
        System.out.println("BFS Traversal:");
        for (int i : ans) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}