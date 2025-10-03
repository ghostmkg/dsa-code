#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct SegTree2D
{
    int n, m;
    vector<vector<ll>> tree;
    SegTree2D(int _n, int _m) : n(_n), m(_m), tree(4 * _n, vector<ll>(4 * _m, 0)) {}
    // Build the y‐tree at x‐node vx covering rows [lx…rx]
    void build_y(int vx, int lx, int rx, int vy, int ly, int ry, const vector<vector<int>> &A)
    {
        if (ly == ry)
        {
            // single column
            if (lx == rx)
            {
                tree[vx][vy] = A[lx][ly];
            }
            else
            {
                tree[vx][vy] = tree[vx * 2 + 1][vy] + tree[vx * 2 + 2][vy];
            }
        }
        else
        {
            int my = (ly + ry) >> 1;
            build_y(vx, lx, rx, vy * 2 + 1, ly, my, A);
            build_y(vx, lx, rx, vy * 2 + 2, my + 1, ry, A);
            tree[vx][vy] = tree[vx][vy * 2 + 1] + tree[vx][vy * 2 + 2];
        }
    }
    // Build over x‐axis [lx…rx]
    void build_x(int vx, int lx, int rx, const vector<vector<int>> &A)
    {
        if (lx < rx)
        {
            int mx = (lx + rx) >> 1;
            build_x(vx * 2 + 1, lx, mx, A);
            build_x(vx * 2 + 2, mx + 1, rx, A);
        }
        build_y(vx, lx, rx, 0, 0, m - 1, A);
    }
    // Query y‐tree at vx over [qly…qry]
    ll query_y(int vx, int vy, int ly, int ry, int qly, int qry)
    {
        if (qry < ly || qly > ry)
            return 0;
        if (qly <= ly && ry <= qry)
            return tree[vx][vy];
        int my = (ly + ry) >> 1;
        return query_y(vx, vy * 2 + 1, ly, my, qly, qry) + query_y(vx, vy * 2 + 2, my + 1, ry, qly, qry);
    }
    // Query rectangle [qlx…qrx] × [qly…qry]
    ll query_x(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry)
    {
        if (qrx < lx || qlx > rx)
            return 0;
        if (qlx <= lx && rx <= qrx)
            return query_y(vx, 0, 0, m - 1, qly, qry);
        int mx = (lx + rx) >> 1;
        return query_x(vx * 2 + 1, lx, mx, qlx, qrx, qly, qry) + query_x(vx * 2 + 2, mx + 1, rx, qlx, qrx, qly, qry);
    }
    // Point‐update in the y‐tree at vx for (ux,uy)
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int ux, int uy, int val)
    {
        if (ly == ry)
        {
            if (lx == rx)
            {
                tree[vx][vy] = val;
            }
            else
            {
                tree[vx][vy] = tree[vx * 2 + 1][vy] + tree[vx * 2 + 2][vy];
            }
        }
        else
        {
            int my = (ly + ry) >> 1;
            if (uy <= my)
                update_y(vx, lx, rx, vy * 2 + 1, ly, my, ux, uy, val);
            else
                update_y(vx, lx, rx, vy * 2 + 2, my + 1, ry, ux, uy, val);
            tree[vx][vy] = tree[vx][vy * 2 + 1] + tree[vx][vy * 2 + 2];
        }
    }
    // Point‐update A[ux][uy] = val
    void update_x(int vx, int lx, int rx, int ux, int uy, int val)
    {
        if (lx < rx)
        {
            int mx = (lx + rx) >> 1;
            if (ux <= mx)
                update_x(vx * 2 + 1, lx, mx, ux, uy, val);
            else
                update_x(vx * 2 + 2, mx + 1, rx, ux, uy, val);
        }
        update_y(vx, lx, rx, 0, 0, m - 1, ux, uy, val);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    // Read grid of '*' / '.'
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = (s[j] == '*');
    }
    SegTree2D st(n, n);
    st.build_x(0, 0, n - 1, a);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            // toggle at (x, y)
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            a[x][y] = 1 - a[x][y]; // flip
            st.update_x(0, 0, n - 1, x, y, a[x][y]);
        }
        else if (type == 2)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1;
            --y1;
            --x2;
            --y2;
            cout << st.query_x(0, 0, n - 1, x1, x2, y1, y2) << "\n";
        }
    }
    return 0;
}