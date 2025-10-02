#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i = (a); i < (b); i++)

vector<int> manacher(const string& s) {
    string t = "@";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";
    int n = t.size();
    vector<int> p(n);
    int c = 0, r = 0;
    rep(i, 1, n - 1) {
        int mir = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mir]);
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

int32_t main() {
    fastio;
    string s; cin >> s;
    vector<int> p = manacher(s);
    int len = 0, center = 0;
    rep(i, 0, p.size()) if (p[i] > len) len = p[i], center = i;
    cout << s.substr((center - len) / 2, len) << "\n";
}