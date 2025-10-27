#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Constructor: create n disjoint sets
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i; // each node is its own parent
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // recursive compression
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // already connected

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    DisjointSet ds(5);

    ds.unite(0, 2);
    ds.unite(4, 2);
    ds.unite(3, 1);

    cout << (ds.find(4) == ds.find(0) ? "Yes" : "No") << endl; // Yes
    cout << (ds.find(1) == ds.find(0) ? "Yes" : "No") << endl; // No

    return 0;
}
