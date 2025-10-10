/*
 * Tarjan's Algorithm for Bridges and Articulation Points in a Graph
 *
 * 👉 What are Bridges?
 * An edge in a graph is a "bridge" if removing it increases the number of connected components.
 *
 * 👉 What are Articulation Points (Cut Vertices)?
 * A vertex is an articulation point if removing it increases the number of connected components.
 *
 * 📌 Why Important?
 * These concepts are critical in:
 *   - Network reliability (finding weak links in a network).
 *   - System design (critical servers or routers).
 *   - Graph theory problems in competitive programming.
 *
 * 📌 Algorithm Idea (Tarjan’s DFS):
 * - Perform DFS traversal of the graph.
 * - Maintain:
 *    1. discovery[] = time when a node is discovered
 *    2. low[] = lowest discovery time reachable from that node
 * - For a node u and its neighbor v:
 *    - If low[v] > discovery[u], then edge (u, v) is a BRIDGE.
 *    - If discovery[u] <= low[v], then u is an ARTICULATION POINT.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

import java.util.*;

public class TarjanBridgesArticulation {
    private int V; // number of vertices
    private List<List<Integer>> adj; // adjacency list
    private int time; // global time for DFS traversal

    private int[] discovery; // discovery time of nodes
    private int[] low;       // lowest discovery time reachable
    private boolean[] visited;
    private boolean[] isArticulation; // articulation marker

    // Constructor
    public TarjanBridgesArticulation(int vertices) {
        this.V = vertices;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        discovery = new int[V];
        low = new int[V];
        visited = new boolean[V];
        isArticulation = new boolean[V];
        time = 0;
    }

    // Add edge (undirected graph)
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // DFS helper
    private void dfs(int u, int parent, List<String> bridges) {
        visited[u] = true;
        discovery[u] = low[u] = ++time; // initialize discovery and low

        int children = 0; // count of children in DFS Tree

        for (int v : adj.get(u)) {
            if (v == parent) continue; // ignore the edge to parent

            if (!visited[v]) {
                children++;
                dfs(v, u, bridges);

                // Update low[u] considering child v
                low[u] = Math.min(low[u], low[v]);

                // --- Bridge condition ---
                if (low[v] > discovery[u]) {
                    bridges.add("Bridge found: (" + u + " - " + v + ")");
                }

                // --- Articulation Point condition ---
                if (parent != -1 && low[v] >= discovery[u]) {
                    isArticulation[u] = true;
                }
            } else {
                // Update low[u] for back edge
                low[u] = Math.min(low[u], discovery[v]);
            }
        }

        // Root articulation condition
        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    // Main function to find Bridges and Articulation Points
    public void findBridgesAndArticulationPoints() {
        List<String> bridges = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, bridges);
            }
        }

        // Print Bridges
        System.out.println("🔗 Bridges in the Graph:");
        if (bridges.isEmpty()) {
            System.out.println("No bridges found.");
        } else {
            for (String b : bridges) System.out.println(b);
        }

        // Print Articulation Points
        System.out.println("\n⚡ Articulation Points in the Graph:");
        boolean foundAP = false;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                System.out.println("Articulation Point: " + i);
                foundAP = true;
            }
        }
        if (!foundAP) {
            System.out.println("No articulation points found.");
        }
    }

    // --- Driver Code / Example ---
    public static void main(String[] args) {
        /*
         * Example Graph:
         *     0 ----- 1
         *     |     / |
         *     |    /  |
         *     |   /   |
         *     2       3
         *             |
         *             4
         */
        TarjanBridgesArticulation graph = new TarjanBridgesArticulation(5);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(3, 4);

        graph.findBridgesAndArticulationPoints();
    }
}
