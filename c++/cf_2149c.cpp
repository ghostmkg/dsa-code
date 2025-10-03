// submission to: https://codeforces.com/contest/2149/problem/C

#include <bits/stdc++.h>
using namespace std;
    
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
    
#define i64 int64_t
#define u64 uint64_t
#define i128 __int128_t
#define u128 __uint128_t
#define ll long long
#define ld long double
#define vi vector<int>
#define vc vector<char>
#define vvc vector<vc>
#define vll vector<ll>
#define vvi vector<vi>
#define vpi vector<pi>
#define vpll vector<pll>
#define uset unordered_set
#define umap unordered_map
#define vs vector<string>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
#define f first
#define s second
#define endl "\n"
#define pb push_back
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define read(v, n) for (int i = 0; i < n; i++) cin >> v[i];
#define rep(i, x, n) for (int i = x; i < n; i++)
    
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
    
const vector<int> d4r = {-1, 1, 0, 0};
const vector<int> d4c = {0, 0, -1, 1};
const vector<int> d8r = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> d8c = {-1, 0, 1, -1, 1, -1, 0, 1};
    
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
    
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
        os << *it << (next(it) != v.end() ? ", " : "");
    return os << "]";
}
    
template<typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& st) {
    os << "{";
    for (auto it = st.begin(); it != st.end(); ++it) {
        os << *it << (next(it) != st.end() ? ", " : "");
    }
    return os << "}";
}
    
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    for (auto it = st.begin(); it != st.end(); ++it) {
        os << *it << (next(it) != st.end() ? ", " : "");
    }
    return os << "}";
}
    
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    for (auto it = st.begin(); it != st.end(); ++it) {
        os << *it << (next(it) != st.end() ? ", " : "");
    }
    return os << "}";
}
    
template<typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& mp) {
    os << "{";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        os << it->first << ": " << it->second;
        if (next(it) != mp.end()) os << ", ";
    }
    return os << "}";
}
    
template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& mp) {
    os << "{";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        os << it->first << ": " << it->second;
        if (next(it) != mp.end()) os << ", ";
    }
    return os << "}";
}
    
#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
    void debug_out() { cerr << endl; }
    template<typename T, typename... Args>
    void debug_out(const T& t, const Args&... args) {
        cerr << t << " ";
        debug_out(args...);
    }
#else
    #define debug(...)
#endif
    
void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    read(v, n);
    if (k != 0) {
        vi c(k + 1, 0);
        for (int i : v) {
            if (i == k) {
                c[k]++;
            }
            else if (i < k) {
                c[i] = 1;
            }
        }   
        int l = 0;
        rep (i, 0, k) {
            if (!c[i]) l++;
        }
        int cnt = min(l, c[k]) + abs(l - c[k]);
        cout << cnt << endl;
    }
    else {
        int cnt = 0;
        for (int i : v) {
            if (i == 0) cnt++;
        }
        cout << cnt << endl;
    }
}
    
int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    int i = 1;
    cin >> t; //jumphere
    while (t--) {
        #ifdef LOCAL
            cout << "Case " << i << '\n';
        #endif
        auto begin = chrono::high_resolution_clock::now();
        solve();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        #ifdef LOCAL
            cout << "t = " << elapsed.count() * 1e-9 << "s\n";
            cout << "--------------------------------------------------\n";
        #endif
        i++;
    }
    
    return 0;
}