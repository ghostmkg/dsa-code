from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def level_order(root):
    """
    Return level order traversal of a binary tree.
    
    Time: O(n), Space: O(n)
    """
    if not root:
        return []
    
    result = []
    q = deque([root])
    
    while q:
        level_size = len(q)
        level = []
        
        for _ in range(level_size):
            node = q.popleft()
            level.append(node.val)
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        
        result.append(level)
    
    return result

# Example usage
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)

print(level_order(root))  # Output: [[3], [9, 20], [15, 7]]