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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (!root) return {};

    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;

        nodes[x][y].insert(node->val);

        if (node->left)
            todo.push({node->left, {x - 1, y + 1}});
        if (node->right)
            todo.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (const auto &p : nodes)
    {
        vector<int> col;
        for (const auto &q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    FAST_IO;

    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);
    for (const auto &col : ans) {
        vprint(col);
    }

    return 0;
}
