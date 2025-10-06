#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check if two trees are mirrors of each other.
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;           // Both null: symmetric here
    if (!t1 || !t2) return false;          // One null, one not: asymmetric
    if (t1->val != t2->val) return false;  // Values differ: asymmetric

    // Check outer and inner pairs recursively
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Construct symmetric tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "Symmetric\n" : "Not symmetric\n");
    return 0;
}
