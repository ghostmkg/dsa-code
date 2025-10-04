#include <bits/stdc++.h>
using namespace std;

#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Level Order Traversal: returns vector of levels, each containing node values at that level
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    FAST_IO;

    // Construct example tree:
    //        3
    //       / \
    //      9  20
    //         /  \
    //        15   7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vmat ans = levelOrder(root);

    // Print the 2D vector (levels)
    for (auto &level : ans) {
        for (auto &val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
