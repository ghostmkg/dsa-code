# Binary Tree Traversal Algorithms
# Time Complexity: O(n) where n is number of nodes
# Space Complexity: O(h) where h is height of tree (O(n) worst case for skewed tree)

class TreeNode:
    """Node class for binary tree."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder_traversal(root):
    """
    Preorder traversal: Root -> Left -> Right
    """
    result = []
    
    def preorder(node):
        if node:
            result.append(node.val)  # Visit root
            preorder(node.left)      # Traverse left subtree
            preorder(node.right)     # Traverse right subtree
    
    preorder(root)
    return result

def inorder_traversal(root):
    """
    Inorder traversal: Left -> Root -> Right
    For BST, this gives sorted order
    """
    result = []
    
    def inorder(node):
        if node:
            inorder(node.left)       # Traverse left subtree
            result.append(node.val)  # Visit root
            inorder(node.right)      # Traverse right subtree
    
    inorder(root)
    return result

def postorder_traversal(root):
    """
    Postorder traversal: Left -> Right -> Root
    """
    result = []
    
    def postorder(node):
        if node:
            postorder(node.left)     # Traverse left subtree
            postorder(node.right)    # Traverse right subtree
            result.append(node.val)  # Visit root
    
    postorder(root)
    return result

def level_order_traversal(root):
    """
    Level order traversal (BFS): Visit nodes level by level
    """
    if not root:
        return []
    
    result = []
    queue = [root]
    
    while queue:
        level_size = len(queue)
        level_nodes = []
        
        for _ in range(level_size):
            node = queue.pop(0)
            level_nodes.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level_nodes)
    
    return result

def iterative_preorder(root):
    """
    Iterative preorder traversal using stack
    """
    if not root:
        return []
    
    result = []
    stack = [root]
    
    while stack:
        node = stack.pop()
        result.append(node.val)
        
        # Push right child first, then left child
        # So left child is processed first
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    
    return result

def iterative_inorder(root):
    """
    Iterative inorder traversal using stack
    """
    result = []
    stack = []
    current = root
    
    while stack or current:
        # Go to the leftmost node
        while current:
            stack.append(current)
            current = current.left
        
        # Process the node
        current = stack.pop()
        result.append(current.val)
        
        # Move to right subtree
        current = current.right
    
    return result

def iterative_postorder(root):
    """
    Iterative postorder traversal using two stacks
    """
    if not root:
        return []
    
    stack1 = [root]
    stack2 = []
    
    while stack1:
        node = stack1.pop()
        stack2.append(node)
        
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)
    
    result = []
    while stack2:
        result.append(stack2.pop().val)
    
    return result

def morris_inorder(root):
    """
    Morris inorder traversal - O(1) space complexity
    """
    result = []
    current = root
    
    while current:
        if not current.left:
            result.append(current.val)
            current = current.right
        else:
            # Find inorder predecessor
            predecessor = current.left
            while predecessor.right and predecessor.right != current:
                predecessor = predecessor.right
            
            if not predecessor.right:
                # Make current as right child of predecessor
                predecessor.right = current
                current = current.left
            else:
                # Revert the changes
                predecessor.right = None
                result.append(current.val)
                current = current.right
    
    return result

def create_sample_tree():
    """
    Create a sample binary tree for testing
    """
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    return root

def create_bst():
    """
    Create a sample BST for testing
    """
    #       4
    #      / \
    #     2   6
    #    / \ / \
    #   1  3 5  7
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(7)
    return root

# Example usage
if __name__ == "__main__":
    print("Binary Tree Traversal Examples")
    print("=" * 50)
    
    # Create sample tree
    root = create_sample_tree()
    print("Sample Tree Structure:")
    print("       1")
    print("      / \\")
    print("     2   3")
    print("    / \\")
    print("   4   5")
    print()
    
    # Recursive traversals
    print("Recursive Traversals:")
    print(f"Preorder:  {preorder_traversal(root)}")
    print(f"Inorder:   {inorder_traversal(root)}")
    print(f"Postorder: {postorder_traversal(root)}")
    print(f"Level Order: {level_order_traversal(root)}")
    print()
    
    # Iterative traversals
    print("Iterative Traversals:")
    print(f"Preorder:  {iterative_preorder(root)}")
    print(f"Inorder:   {iterative_inorder(root)}")
    print(f"Postorder: {iterative_postorder(root)}")
    print()
    
    # Morris traversal
    print("Morris Inorder Traversal (O(1) space):")
    print(f"Inorder:   {morris_inorder(root)}")
    print()
    
    # BST example
    print("BST Traversal (Inorder gives sorted order):")
    bst_root = create_bst()
    print(f"Inorder:   {inorder_traversal(bst_root)}")
    print(f"Level Order: {level_order_traversal(bst_root)}")
    print()
    
    # Edge cases
    print("Edge Cases:")
    print(f"Empty tree preorder: {preorder_traversal(None)}")
    print(f"Single node preorder: {preorder_traversal(TreeNode(42))}")
