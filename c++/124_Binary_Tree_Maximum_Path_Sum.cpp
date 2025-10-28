#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};