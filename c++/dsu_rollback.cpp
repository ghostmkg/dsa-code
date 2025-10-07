// dsu_rollback.cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<pair<int,int>> ops;
    DSU(int n): parent(n), sz(n,1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x){ while (x!=parent[x]) x = parent[x]; return x; }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if (a==b){ ops.emplace_back(-1,-1); return; }
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a; sz[a] += sz[b];
        ops.emplace_back(a,b);
    }
    void snapshot(){ ops.clear(); }
    void rollback(){
        if (ops.empty()) return;
        auto [a,b] = ops.back(); ops.pop_back();
        if (a == -1 && b == -1) return;
        sz[a] -= sz[b]; parent[b] = b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Simple demo: unite 0-1, 1-2, rollback last union.
    DSU dsu(5);
    dsu.unite(0,1);
    dsu.unite(1,2);
    cout << (dsu.find(0) == dsu.find(2)) << "\n"; // 1
    dsu.rollback();
    cout << (dsu.find(0) == dsu.find(2)) << "\n"; // 0
    return 0;
}
