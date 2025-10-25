# Binary Tree Validation Algorithms
# Various algorithms to validate properties of binary trees

class TreeNode:
    """Node class for binary tree."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    """
    Validate if a binary tree is a valid BST.
    Time Complexity: O(n)
    Space Complexity: O(h) where h is height of tree
    """
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (validate(node.left, min_val, node.val) and 
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))

def is_balanced_binary_tree(root):
    """
    Check if a binary tree is height-balanced.
    A balanced tree is one where the heights of two child subtrees 
    of any node differ by at most 1.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    def get_height(node):
        if not node:
            return 0
        
        left_height = get_height(node.left)
        if left_height == -1:
            return -1
        
        right_height = get_height(node.right)
        if right_height == -1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1
        
        return max(left_height, right_height) + 1
    
    return get_height(root) != -1

def is_symmetric_tree(root):
    """
    Check if a binary tree is symmetric around its center.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    def is_mirror(left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        return (left.val == right.val and 
                is_mirror(left.left, right.right) and 
                is_mirror(left.right, right.left))
    
    if not root:
        return True
    return is_mirror(root.left, root.right)

def is_same_tree(p, q):
    """
    Check if two binary trees are identical.
    Time Complexity: O(min(m, n)) where m, n are number of nodes
    Space Complexity: O(min(m, n))
    """
    if not p and not q:
        return True
    if not p or not q:
        return False
    return (p.val == q.val and 
            is_same_tree(p.left, q.left) and 
            is_same_tree(p.right, q.right))

def is_subtree(root, subRoot):
    """
    Check if subRoot is a subtree of root.
    Time Complexity: O(m * n) where m, n are number of nodes
    Space Complexity: O(h)
    """
    if not subRoot:
        return True
    if not root:
        return False
    
    if is_same_tree(root, subRoot):
        return True
    
    return is_subtree(root.left, subRoot) or is_subtree(root.right, subRoot)

def is_complete_binary_tree(root):
    """
    Check if a binary tree is complete.
    A complete binary tree is one where all levels are completely filled
    except possibly the last level, which is filled from left to right.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if not root:
        return True
    
    queue = [(root, 0)]
    expected_index = 0
    
    while queue:
        node, index = queue.pop(0)
        
        if index != expected_index:
            return False
        
        expected_index += 1
        
        if node.left:
            queue.append((node.left, 2 * index + 1))
        if node.right:
            queue.append((node.right, 2 * index + 2))
    
    return True

def is_perfect_binary_tree(root):
    """
    Check if a binary tree is perfect.
    A perfect binary tree is one where all internal nodes have exactly
    two children and all leaves are at the same level.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    def get_depth(node):
        depth = 0
        while node:
            depth += 1
            node = node.left
        return depth
    
    def is_perfect(node, depth, level):
        if not node:
            return True
        
        # If leaf node, check if it's at the last level
        if not node.left and not node.right:
            return depth == level + 1
        
        # If internal node, check both children
        if not node.left or not node.right:
            return False
        
        return (is_perfect(node.left, depth, level + 1) and 
                is_perfect(node.right, depth, level + 1))
    
    depth = get_depth(root)
    return is_perfect(root, depth, 0)

def is_full_binary_tree(root):
    """
    Check if a binary tree is full.
    A full binary tree is one where every node has either 0 or 2 children.
    Time Complexity: O(n)
    Space Complexity: O(h)
    """
    if not root:
        return True
    
    # If leaf node
    if not root.left and not root.right:
        return True
    
    # If internal node, both children must exist
    if root.left and root.right:
        return (is_full_binary_tree(root.left) and 
                is_full_binary_tree(root.right))
    
    return False

def create_test_trees():
    """Create various test trees for validation."""
    trees = {}
    
    # Valid BST
    #       4
    #      / \
    #     2   6
    #    / \ / \
    #   1  3 5  7
    bst = TreeNode(4)
    bst.left = TreeNode(2)
    bst.right = TreeNode(6)
    bst.left.left = TreeNode(1)
    bst.left.right = TreeNode(3)
    bst.right.left = TreeNode(5)
    bst.right.right = TreeNode(7)
    trees['valid_bst'] = bst
    
    # Invalid BST
    #       5
    #      / \
    #     1   4
    #        / \
    #       3   6
    invalid_bst = TreeNode(5)
    invalid_bst.left = TreeNode(1)
    invalid_bst.right = TreeNode(4)
    invalid_bst.right.left = TreeNode(3)
    invalid_bst.right.right = TreeNode(6)
    trees['invalid_bst'] = invalid_bst
    
    # Symmetric tree
    #       1
    #      / \
    #     2   2
    #    / \ / \
    #   3  4 4  3
    symmetric = TreeNode(1)
    symmetric.left = TreeNode(2)
    symmetric.right = TreeNode(2)
    symmetric.left.left = TreeNode(3)
    symmetric.left.right = TreeNode(4)
    symmetric.right.left = TreeNode(4)
    symmetric.right.right = TreeNode(3)
    trees['symmetric'] = symmetric
    
    # Complete binary tree
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    complete = TreeNode(1)
    complete.left = TreeNode(2)
    complete.right = TreeNode(3)
    complete.left.left = TreeNode(4)
    complete.left.right = TreeNode(5)
    trees['complete'] = complete
    
    return trees

# Example usage
if __name__ == "__main__":
    print("Binary Tree Validation Examples")
    print("=" * 50)
    
    trees = create_test_trees()
    
    # Test BST validation
    print("BST Validation:")
    print(f"Valid BST: {is_valid_bst(trees['valid_bst'])}")
    print(f"Invalid BST: {is_valid_bst(trees['invalid_bst'])}")
    print()
    
    # Test balanced tree
    print("Balanced Tree Check:")
    print(f"Valid BST (balanced): {is_balanced_binary_tree(trees['valid_bst'])}")
    print(f"Symmetric tree (balanced): {is_balanced_binary_tree(trees['symmetric'])}")
    print()
    
    # Test symmetric tree
    print("Symmetric Tree Check:")
    print(f"Symmetric tree: {is_symmetric_tree(trees['symmetric'])}")
    print(f"Valid BST (not symmetric): {is_symmetric_tree(trees['valid_bst'])}")
    print()
    
    # Test complete tree
    print("Complete Binary Tree Check:")
    print(f"Complete tree: {is_complete_binary_tree(trees['complete'])}")
    print(f"Valid BST (not complete): {is_complete_binary_tree(trees['valid_bst'])}")
    print()
    
    # Test perfect tree
    print("Perfect Binary Tree Check:")
    print(f"Valid BST (perfect): {is_perfect_binary_tree(trees['valid_bst'])}")
    print(f"Complete tree (not perfect): {is_perfect_binary_tree(trees['complete'])}")
    print()
    
    # Test full tree
    print("Full Binary Tree Check:")
    print(f"Valid BST (full): {is_full_binary_tree(trees['valid_bst'])}")
    print(f"Complete tree (full): {is_full_binary_tree(trees['complete'])}")
    print()
    
    # Test same tree
    print("Same Tree Check:")
    print(f"Same trees: {is_same_tree(trees['valid_bst'], trees['valid_bst'])}")
    print(f"Different trees: {is_same_tree(trees['valid_bst'], trees['symmetric'])}")
    print()
    
    # Edge cases
    print("Edge Cases:")
    print(f"Empty tree is BST: {is_valid_bst(None)}")
    print(f"Empty tree is balanced: {is_balanced_binary_tree(None)}")
    print(f"Empty tree is symmetric: {is_symmetric_tree(None)}")
    print(f"Single node is BST: {is_valid_bst(TreeNode(5))}")
    print(f"Single node is balanced: {is_balanced_binary_tree(TreeNode(5))}")
