#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define vint vector<int>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Gets the left boundary without leaf nodes
void getLeftBoundary(TreeNode *node, vector<int> &ans)
{
    while (node)
    {
        if (node->left || node->right) // Not a leaf
            ans.push_back(node->val);

        if (node->left)
            node = node->left;
        else
            node = node->right;
    }
}

// Gets the right boundary without leaf nodes
void getRightBoundary(TreeNode *node, vector<int> &ans)
{
    vector<int> temp;
    while (node)
    {
        if (node->left || node->right) // Not a leaf
            temp.push_back(node->val);

        if (node->right)
            node = node->right;
        else
            node = node->left;
    }
    // Add right boundary in reverse order
    for (int i = (int)temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}

// Gets all leaf nodes in left-to-right order
void getLeafNodes(TreeNode *node, vector<int> &ans)
{
    if (!node)
        return;
    if (!node->left && !node->right)
    {
        ans.push_back(node->val);
        return;
    }
    getLeafNodes(node->left, ans);
    getLeafNodes(node->right, ans);
}

// Returns the boundary traversal of the tree
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    // Add root value if it is not a leaf node
    if (root->left || root->right)
        ans.push_back(root->val);

    // Get left boundary
    getLeftBoundary(root->left, ans);

    // Get leaf nodes
    getLeafNodes(root, ans);

    // Get right boundary
    getRightBoundary(root->right, ans);

    return ans;
}

int main()
{
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

    vint ans = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    vprint(ans);

    return 0;
}
