import java.util.*;

public class DetectCycleInDirectedGraph {
    private final int vertices;
    private final List<List<Integer>> adjList;

    DetectCycleInDirectedGraph(int v) {
        vertices = v;
        adjList = new ArrayList<>();
        for (int i = 0; i < v; i++)
            adjList.add(new ArrayList<>());
    }

    void addEdge(int u, int v) {
        adjList.get(u).add(v);
    }

    boolean isCyclicUtil(int node, boolean[] visited, boolean[] recStack) {
        if (recStack[node])
            return true;
        if (visited[node])
            return false;

        visited[node] = true;
        recStack[node] = true;

        for (Integer neighbor : adjList.get(node)) {
            if (isCyclicUtil(neighbor, visited, recStack))
                return true;
        }

        recStack[node] = false;
        return false;
    }

    boolean isCyclic() {
        boolean[] visited = new boolean[vertices];
        boolean[] recStack = new boolean[vertices];

        for (int i = 0; i < vertices; i++) {
            if (isCyclicUtil(i, visited, recStack))
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        DetectCycleInDirectedGraph graph = new DetectCycleInDirectedGraph(4);
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(2, 0); // cycle
        graph.addEdge(2, 3);

        if (graph.isCyclic())
            System.out.println("Graph contains a cycle");
        else
            System.out.println("Graph does not contain a cycle");
    }
}
