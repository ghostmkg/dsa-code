# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        # Helper function to check if two trees are identical
        def isSameTree(s, t):
            if not s and not t:
                return True
            if not s or not t:
                return False
            return (s.val == t.val and
                    isSameTree(s.left, t.left) and
                    isSameTree(s.right, t.right))
        
        # Main logic: check if subRoot is a subtree starting from any node in root
        if not root:
            return False
        if isSameTree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


# -------- Example Usage --------
# Example 1:
# root = [3,4,5,1,2], subRoot = [4,1,2]
#       3
#      / \
#     4   5
#    / \
#   1   2

root = TreeNode(3)
root.left = TreeNode(4)
root.right = TreeNode(5)
root.left.left = TreeNode(1)
root.left.right = TreeNode(2)

subRoot = TreeNode(4)
subRoot.left = TreeNode(1)
subRoot.right = TreeNode(2)

sol = Solution()
print("Is Subtree:", sol.isSubtree(root, subRoot))  # Output: True
