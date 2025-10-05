function warshall(graph) {
  const n = graph.length;
  const reach = Array.from({ length: n }, (_, i) => [...graph[i]]);

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
      }
    }
  }

  return reach;
}

const graph = [
  [1, 1, 0, 0],
  [0, 1, 1, 0],
  [0, 0, 1, 1],
  [0, 0, 0, 1],
];

const closure = warshall(graph);
console.log(closure);
