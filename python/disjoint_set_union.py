class DisjointSetUnion:
    """
    Disjoint Set Union (Union-Find) data structure with path compression
    and union by rank optimization.
    
    Used for: Connected components, Kruskal's MST, cycle detection
    Time: O(α(n)) ≈ O(1) for both union and find operations
    """
    
    def __init__(self, n):
        """Initialize n elements, each in its own set"""
        self.parent = list(range(n))
        self.rank = [0] * n
        self.size = [1] * n
    
    def find(self, x):
        """Find the root of element x with path compression"""
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        """Union two sets containing x and y"""
        root_x = self.find(x)
        root_y = self.find(y)
        
        if root_x == root_y:
            return False  # Already in same set
        
        # Union by rank
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
            self.size[root_y] += self.size[root_x]
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]
        else:
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]
            self.rank[root_x] += 1
        
        return True
    
    def connected(self, x, y):
        """Check if x and y are in the same set"""
        return self.find(x) == self.find(y)
    
    def get_size(self, x):
        """Get the size of the set containing x"""
        return self.size[self.find(x)]


# Example usage: Number of connected components
def count_components(n, edges):
    """
    Count number of connected components in an undirected graph.
    
    Args:
        n: number of nodes (0 to n-1)
        edges: list of [u, v] edges
    
    Returns:
        number of connected components
    """
    dsu = DisjointSetUnion(n)
    
    for u, v in edges:
        dsu.union(u, v)
    
    # Count unique roots
    return len(set(dsu.find(i) for i in range(n)))


# Test cases
if __name__ == "__main__":
    # Example 1: Simple connected components
    n = 5
    edges = [[0, 1], [1, 2], [3, 4]]
    print(f"Components: {count_components(n, edges)}")  # Output: 2
    
    # Example 2: Detecting cycle
    dsu = DisjointSetUnion(4)
    edges = [[0, 1], [1, 2], [2, 3], [3, 0]]
    
    has_cycle = False
    for u, v in edges:
        if dsu.connected(u, v):
            has_cycle = True
            print(f"Cycle detected at edge ({u}, {v})")
            break
        dsu.union(u, v)
    
    # Example 3: Size tracking
    dsu2 = DisjointSetUnion(6)
    dsu2.union(0, 1)
    dsu2.union(1, 2)
    print(f"Size of component containing 0: {dsu2.get_size(0)}")  # Output: 3