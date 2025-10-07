// li_chao_tree.cpp
// Li Chao Tree for min over lines y = m*x + b (x is int)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);

struct Line {
    ll m, b;
    Line(ll mm=0, ll bb=INF): m(mm), b(bb) {}
    ll eval(ll x) const { return m*x + b; }
};

struct LiChao {
    struct Node { Line line; Node *l, *r; Node(Line ln): line(ln), l(nullptr), r(nullptr) {} };
    ll L, R;
    Node* root;
    LiChao(ll l, ll r): L(l), R(r), root(nullptr) {}
    void insert(Line nw) { root = insert(root, L, R, nw); }
    Node* insert(Node* node, ll l, ll r, Line nw) {
        if (!node) return new Node(nw);
        ll mid = (l + r) >> 1;
        bool lef = nw.eval(l) < node->line.eval(l);
        bool m   = nw.eval(mid) < node->line.eval(mid);
        if (m) {
            swap(nw, node->line);
        }
        if (r==l) return node;
        else if (lef != m) {
            node->l = insert(node->l, l, mid, nw);
        } else {
            node->r = insert(node->r, mid+1, r, nw);
        }
        return node;
    }
    ll query(ll x) { return query(root, L, R, x); }
    ll query(Node* node, ll l, ll r, ll x) {
        if (!node) return INF;
        ll res = node->line.eval(x);
        if (l==r) return res;
        ll mid = (l+r)>>1;
        if (x <= mid) return min(res, query(node->l, l, mid, x));
        else return min(res, query(node->r, mid+1, r, x));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example: lines representing y = m*x + b
    LiChao tree(-1000000, 1000000);
    tree.insert(Line(1, 0));   // y = x
    tree.insert(Line(-1, 100)); // y = -x + 100
    cout << "min at x=10: " << tree.query(10) << "\n";
    cout << "min at x=1000: " << tree.query(1000) << "\n";
    return 0;
}
