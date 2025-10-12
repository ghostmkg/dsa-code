// https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

// User function Template for C++

/*
struct Node {
    int key;
    Node *left, *right;
};
*/

class Solution
{
public:
    int solve(Node *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        ans += abs(left) + abs(right);
        int extraCandies = root->key + left + right - 1;
        return extraCandies;
    }
    int distributeCandy(Node *root)
    {
        // code here
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};