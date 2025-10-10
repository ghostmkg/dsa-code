def topo_sort_dfs(graph)
  visited = {}
  stack = []

  graph.keys.each do |node|
    dfs(node, graph, visited, stack) unless visited[node]
  end

  stack.reverse  # topological order
end

def dfs(node, graph, visited, stack)
  visited[node] = true
  graph[node].each do |neighbor|
    dfs(neighbor, graph, visited, stack) unless visited[neighbor]
  end
  stack << node
end

# Example usage
graph = {
  5 => [0, 2],
  4 => [0, 1],
  2 => [3],
  3 => [1],
  0 => [],
  1 => []
}

order = topo_sort_dfs(graph)
puts "Topological Order (DFS): #{order.inspect}"
