class DSU:
    def __init__(self, n):
        # Initially, each node is its own parent
        self.parent = [i for i in range(n)]
        self.rank = [0] * n  # Rank for union by rank

    def find(self, x):
        if self.parent[x] != x:
            # Path compression
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)

        if xroot == yroot:
            return  # Already in the same set

        # Union by rank
        if self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        elif self.rank[xroot] > self.rank[yroot]:
            self.parent[yroot] = xroot
        else:
            self.parent[yroot] = xroot
            self.rank[xroot] += 1

# Example usage
if __name__ == "__main__":
    n = 5
    dsu = DSU(n)

    # Merge sets
    dsu.union(0, 1)
    dsu.union(1, 2)
    dsu.union(3, 4)

    # Find representatives
    for i in range(n):
        print(f"Parent of {i}: {dsu.find(i)}")
