#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2) {
    if (!root1 || !root2) 
        return root1 == root2;
    return (root1->val == root2->val) &&
           isSymmetricUtil(root1->left, root2->right) &&
           isSymmetricUtil(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isSymmetricUtil(root->left, root->right);
}

int main() {
    FAST_IO;

    // Sample symmetric tree
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
