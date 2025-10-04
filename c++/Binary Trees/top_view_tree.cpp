#include <bits/stdc++.h>
using namespace std;

#define vint vector<int>
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS traversal collecting nodes by (x,y) without structured bindings
map<int, map<int, multiset<int>>> bfsCollect(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    if (!root) return nodes;

    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
        pair<TreeNode*, pair<int,int>> p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->val);

        if (node->left)
            q.push(make_pair(node->left, make_pair(x - 1, y + 1)));
        if (node->right)
            q.push(make_pair(node->right, make_pair(x + 1, y + 1)));
    }
    return nodes;
}

vint topView(TreeNode* root) {
    vint ans;
    auto nodes = bfsCollect(root);

    // For each horizontal distance, pick the topmost node (smallest y)
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        auto &levelMap = it->second;
        auto levelIt = levelMap.begin(); // smallest y
        ans.push_back(*levelIt->second.begin());
    }
    return ans;
}

vint bottomView(TreeNode* root) {
    vint ans;
    auto nodes = bfsCollect(root);

    // For each horizontal distance, pick the bottommost node (largest y)
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        auto &levelMap = it->second;
        auto levelIt = --levelMap.end(); // largest y
        ans.push_back(*--(levelIt->second.end()));
    }
    return ans;
}

int main() {
    FAST_IO;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vint ansBottom = bottomView(root);
    cout << "Bottom View: ";
    vprint(ansBottom);

    vint ansTop = topView(root);
    cout << "Top View: ";
    vprint(ansTop);

    return 0;
}
