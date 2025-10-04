#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to perform Zig-Zag (Spiral) Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // if leftToRight is true, fill normally, else fill in reverse order
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(level);
        leftToRight = !leftToRight; // switch direction
    }

    return ans;
}

int main()
{
    FAST_IO;

    // 🌳 Sample Tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //
    // Zig-Zag Output: [1] [3 2] [4 5 6 7]

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zig-Zag Traversal:\n";
    for (auto &level : result)
    {
        vprint(level);
    }

    return 0;
}
// by ad73prem
