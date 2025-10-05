/**
 * Edge definition: [u, v, weight]
 */
type Edge = [number, number, number];

/**
 * Computes the Minimum Spanning Tree of a weighted, connected, undirected graph
 * using Kruskal's Algorithm.
 *
 * @param numVertices The total number of vertices (0 to numVertices - 1).
 * @param edges An array of edges, where each edge is [u, v, weight].
 * @returns An array of edges that form the MST.
 */
function kruskalMST(numVertices: number, edges: Edge[]): Edge[] {
  const mst: Edge[] = [];

  // 1. Sort all edges by weight in non-decreasing order.
  edges.sort((a, b) => a[2] - b[2]);

  // 2. Initialize the Union-Find structure.
  const uf = new UnionFind(numVertices);

  // 3. Iterate through the sorted edges.
  for (const [u, v, weight] of edges) {
    // 4. Check if adding the edge (u, v) creates a cycle.
    // If the roots of u and v are different, they are in different components (no cycle).
    if (uf.find(u) !== uf.find(v)) {
      // Add the edge to the MST.
      mst.push([u, v, weight]);

      // Merge the two components.
      uf.union(u, v);

      // Optimization: The MST must have V-1 edges. Stop when this is reached.
      if (mst.length === numVertices - 1) {
        break;
      }
    }
  }

  return mst;
}
