#include <bits/stdc++.h>
using namespace std;

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
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// Helper function returns the height of the tree if balanced
// Returns -1 if the subtree is unbalanced
int checkHeight(TreeNode *root) {
    if (!root)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;  // Left subtree not balanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1; // Right subtree not balanced

    // If height difference is more than 1, unbalanced
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // Return height of subtree rooted at current node
    return max(leftHeight, rightHeight) + 1;
}

// Returns true if the tree is height-balanced, false otherwise
bool isBalanced(TreeNode *root) {
    return checkHeight(root) != -1;
}

int main() {
    FAST_IO;

    // Example usage: create a balanced tree
    TreeNode *root = new TreeNode(1,
                        new TreeNode(2,
                            new TreeNode(4),
                            new TreeNode(5)),
                        new TreeNode(3));

    if (isBalanced(root))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    return 0;
}
