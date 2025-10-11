#Recursive Approach
#python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root):
        """
        Check if a binary tree is symmetric (mirror of itself).
        
        Args:
            root: TreeNode - root of the binary tree
            
        Returns:
            bool: True if tree is symmetric, False otherwise
        """
        if not root:
            return True
        
        def isMirror(left, right):
            """
            Helper function to check if two trees are mirrors of each other.
            """
            # If both nodes are None, they are symmetric
            if not left and not right:
                return True
            
            # If one is None and other is not, they are not symmetric
            if not left or not right:
                return False
            
            # Check if values are equal and subtrees are mirrors
            return (left.val == right.val and 
                    isMirror(left.left, right.right) and 
                    isMirror(left.right, right.left))
        
        return isMirror(root.left, root.right)