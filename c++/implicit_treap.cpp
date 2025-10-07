// implicit_treap.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
    int val, pr, sz;
    bool rev;
    Node *l, *r;
    Node(int v): val(v), pr(rand()), sz(1), rev(false), l(nullptr), r(nullptr) {}
};
int sz(Node* t){ return t? t->sz : 0; }
void push(Node* t){
    if (!t || !t->rev) return;
    t->rev = false;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
}
void upd(Node* t){
    if (!t) return;
    t->sz = 1 + sz(t->l) + sz(t->r);
}
void split(Node* t, int k, Node*& a, Node*& b){ // first k go to a
    if (!t) { a=b=nullptr; return; }
    push(t);
    if (sz(t->l) >= k) {
        split(t->l, k, a, t->l); b = t; upd(b);
    } else {
        split(t->r, k - sz(t->l) - 1, t->r, b); a = t; upd(a);
    }
}
Node* merge(Node* a, Node* b){
    if (!a || !b) return a? a : b;
    if (a->pr < b->pr) { push(a); a->r = merge(a->r, b); upd(a); return a; }
    else { push(b); b->l = merge(a, b->l); upd(b); return b; }
}
// convenience: build from vector
Node* build(const vector<int>& v){
    Node* t = nullptr;
    for (int x : v) t = merge(t, new Node(x));
    return t;
}
int get_kth(Node* t, int k){ // 0-indexed
    push(t);
    if (!t) return -1;
    if (sz(t->l) == k) return t->val;
    if (sz(t->l) > k) return get_kth(t->l, k);
    return get_kth(t->r, k - sz(t->l) - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    vector<int> init = {1,2,3,4,5};
    Node* root = build(init);
    // reverse subarray [1,3] (0-indexed, inclusive)
    Node *a, *b, *c;
    split(root, 1, a, b); // a = [0], b=[1..]
    split(b, 3, b, c); // b=[1..3], c=[4..]
    if (b) b->rev ^= 1;
    root = merge(a, merge(b, c));
    for (int i=0;i<sz(root);++i) cout << get_kth(root,i) << " ";
    cout << "\n";
    return 0;
}
