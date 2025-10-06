#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Returns the maximum depth (height) of a binary tree.
// Time Complexity: O(n), where n is the number of nodes.
int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Helper to create a simple binary tree for testing.
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = createSampleTree();
    cout << "Maximum Depth of the tree: " << maxDepth(root) << "\n";

    return 0;
}
