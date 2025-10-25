import java.util.*;

public class Dfs {
    private int V; // Number of vertices
    private LinkedList<Integer>[] adj; // Adjacency lists

    // Constructor
    public Dfs(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    public void addEdge(int v, int w) {
        adj[v].add(w);
    }

    // DFS traversal from a given source
    public void DFS(int start) {
        boolean[] visited = new boolean[V];
        dfsUtil(start, visited);
    }

    // Utility function for DFS
    private void dfsUtil(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");

        for (int n : adj[v]) {
            if (!visited[n]) {
                dfsUtil(n, visited);
            }
        }
    }

    // Sample usage
    public static void main(String[] args) {
        Dfs graph = new Dfs(4);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 0);
        graph.addEdge(2, 3);
        graph.addEdge(3, 3);

        System.out.println("DFS starting from vertex 2:");
        graph.DFS(2);
    }
}
