// suffix_automaton.cpp
// Suffix Automaton: build in O(n), count distinct substrings
#include <bits/stdc++.h>
using namespace std;

struct State {
    int len, link;
    array<int, 26> next;
    State(): len(0), link(-1) { next.fill(-1); }
};

struct SuffixAutomaton {
    vector<State> st;
    int last;
    SuffixAutomaton(){ st.reserve(2e5); st.push_back(State()); last = 0; }
    void extend(char ch) {
        int c = ch - 'a';
        int cur = st.size(); st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p!=-1 && st[p].next[c]==-1) {
            st[p].next[c] = cur; p = st[p].link;
        }
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                st.push_back(st[q]);
                int clone = st.size()-1;
                st[clone].len = st[p].len + 1;
                // copy transitions already done by push_back(st[q])
                st[q].link = st[cur].link = clone;
                while (p!=-1 && st[p].next[c]==q) {
                    st[p].next[c] = clone; p = st[p].link;
                }
            }
        }
        last = cur;
    }
    long long countDistinctSubstrings() {
        long long ans = 0;
        for (int i=1;i<(int)st.size();++i) {
            ans += st[i].len - st[st[i].link].len;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    SuffixAutomaton sam;
    for (char c : s) sam.extend(c);
    cout << sam.countDistinctSubstrings() << "\n";
    return 0;
}
