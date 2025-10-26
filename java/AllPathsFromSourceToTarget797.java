public class AllPathsFromSourceToTarget797 {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        if (graph == null || graph.length == 0) return res;
        int N = graph.length;
        backtrace(graph, 0, N-1, new ArrayList<>(), res, N);
        return res;
    }

    private void backtrace(int[][] graph, int current, int dest, List<Integer> path, List<List<Integer>> res, int N) {
        if (current == dest) {
            path.add(current);
            res.add(new ArrayList<>(path));
            path.remove(path.size() - 1);
            return;
        }
        
        path.add(current);
        for (int child: graph[current]) {
            backtrace(graph, child, N-1, path, res, N);
        }
        path.remove(path.size() - 1);
    }


    public List<List<Integer>> allPathsSourceTarget2(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        if (graph == null || graph.length == 0) return res;
        int N = graph.length;
        List<Integer> path = new ArrayList<>();
        path.add(0);
        backtrace2(graph, 0, N-1, path, res, N);
        return res;
    }

    private void backtrace2(int[][] graph, int current, int dest, List<Integer> path, List<List<Integer>> res, int N) {
        if (current == dest) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int child: graph[current]) {
            path.add(child);
            backtrace2(graph, child, N-1, path, res, N);
            path.remove(path.size() - 1);
        }
    }

}
