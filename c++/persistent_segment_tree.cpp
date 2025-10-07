// persistent_segment_tree.cpp
// Persistent segment tree for point update + range sum query
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum;
    Node *l, *r;
    Node(ll s=0, Node* L=nullptr, Node* R=nullptr): sum(s), l(L), r(R) {}
};

Node* build(int tl, int tr, const vector<ll>& a) {
    if (tl == tr) return new Node(a[tl]);
    int tm = (tl+tr)/2;
    return new Node(
        0,
        build(tl, tm, a),
        build(tm+1, tr, a)
    );
}
Node* update(Node* v, int tl, int tr, int pos, ll val) {
    if (tl == tr) return new Node(val);
    int tm = (tl+tr)/2;
    if (pos <= tm) {
        Node* nl = update(v->l, tl, tm, pos, val);
        return new Node(nl->sum + v->r->sum, nl, v->r);
    } else {
        Node* nr = update(v->r, tm+1, tr, pos, val);
        return new Node(v->l->sum + nr->sum, v->l, nr);
    }
}
ll query(Node* v, int tl, int tr, int l, int r) {
    if (!v || l>r) return 0;
    if (l<=tl && tr<=r) return v->sum;
    int tm = (tl+tr)/2;
    ll res = 0;
    if (l <= tm) res += query(v->l, tl, tm, l, min(r, tm));
    if (r > tm) res += query(v->r, tm+1, tr, max(l, tm+1), r);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example: build initial array, then create versions with updates and query them.
    int n = 8;
    vector<ll> a(n);
    for (int i=0;i<n;i++) a[i] = i+1;
    Node* root0 = build(0, n-1, a);
    // version 1: a[3] = 100
    Node* root1 = update(root0, 0, n-1, 3, 100);
    // version 2: a[0] = 42 based on root1
    Node* root2 = update(root1, 0, n-1, 0, 42);

    cout << "sum root0 [0,3] = " << query(root0,0,n-1,0,3) << "\n"; // 1+2+3+4=10
    cout << "sum root1 [0,3] = " << query(root1,0,n-1,0,3) << "\n"; // 1+2+3+100=106
    cout << "sum root2 [0,0] = " << query(root2,0,n-1,0,0) << "\n"; // 42
    return 0;
}
