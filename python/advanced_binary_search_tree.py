"""
Advanced Binary Search Tree Implementation

This module provides a comprehensive BST implementation with advanced operations
including deletion, validation, balancing, and various tree analysis methods.

Features:
- Complete CRUD operations (Create, Read, Update, Delete)
- Tree validation and balancing
- Multiple traversal methods
- Tree statistics and analysis
- Visualization support

Time Complexities:
- Search/Insert/Delete: O(log n) average, O(n) worst case
- Traversals: O(n)
- Validation: O(n)

Author: Hacktoberfest Contributor
Date: October 2024
"""

from typing import Optional, List, Any
import math
from collections import deque


class TreeNode:
    """Binary Search Tree Node"""
    
    def __init__(self, val: int = 0):
        self.val = val
        self.left: Optional['TreeNode'] = None
        self.right: Optional['TreeNode'] = None
        self.count = 1  # For handling duplicates
        
    def __str__(self):
        return f"TreeNode({self.val})"
    
    def __repr__(self):
        return self.__str__()


class AdvancedBST:
    """Advanced Binary Search Tree with comprehensive operations"""
    
    def __init__(self):
        self.root: Optional[TreeNode] = None
        self.size = 0
    
    def insert(self, val: int) -> None:
        """Insert a value into the BST"""
        if not self.root:
            self.root = TreeNode(val)
            self.size = 1
            return
        
        self._insert_recursive(self.root, val)
    
    def _insert_recursive(self, node: TreeNode, val: int) -> TreeNode:
        """Helper method for recursive insertion"""
        if val < node.val:
            if node.left is None:
                node.left = TreeNode(val)
                self.size += 1
            else:
                self._insert_recursive(node.left, val)
        elif val > node.val:
            if node.right is None:
                node.right = TreeNode(val)
                self.size += 1
            else:
                self._insert_recursive(node.right, val)
        else:
            # Handle duplicates by incrementing count
            node.count += 1
        
        return node
    
    def search(self, val: int) -> Optional[TreeNode]:
        """Search for a value in the BST"""
        return self._search_recursive(self.root, val)
    
    def _search_recursive(self, node: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        """Helper method for recursive search"""
        if not node or node.val == val:
            return node
        
        if val < node.val:
            return self._search_recursive(node.left, val)
        else:
            return self._search_recursive(node.right, val)
    
    def delete(self, val: int) -> bool:
        """Delete a value from the BST"""
        self.root, deleted = self._delete_recursive(self.root, val)
        if deleted:
            self.size -= 1
        return deleted
    
    def _delete_recursive(self, node: Optional[TreeNode], val: int) -> tuple[Optional[TreeNode], bool]:
        """Helper method for recursive deletion"""
        if not node:
            return None, False
        
        deleted = False
        
        if val < node.val:
            node.left, deleted = self._delete_recursive(node.left, val)
        elif val > node.val:
            node.right, deleted = self._delete_recursive(node.right, val)
        else:
            # Found the node to delete
            if node.count > 1:
                # Handle duplicates
                node.count -= 1
                return node, True
            
            # Node has no children
            if not node.left and not node.right:
                return None, True
            
            # Node has one child
            if not node.left:
                return node.right, True
            if not node.right:
                return node.left, True
            
            # Node has two children - find inorder successor
            successor = self._find_min(node.right)
            node.val = successor.val
            node.count = successor.count
            successor.count = 1  # Avoid double decrement
            node.right, _ = self._delete_recursive(node.right, successor.val)
            deleted = True
        
        return node, deleted
    
    def _find_min(self, node: TreeNode) -> TreeNode:
        """Find the minimum value node in a subtree"""
        while node.left:
            node = node.left
        return node
    
    def _find_max(self, node: TreeNode) -> TreeNode:
        """Find the maximum value node in a subtree"""
        while node.right:
            node = node.right
        return node
    
    # Traversal Methods
    def inorder_traversal(self) -> List[int]:
        """Inorder traversal (left, root, right) - gives sorted order"""
        result = []
        self._inorder_recursive(self.root, result)
        return result
    
    def _inorder_recursive(self, node: Optional[TreeNode], result: List[int]) -> None:
        """Helper for inorder traversal"""
        if node:
            self._inorder_recursive(node.left, result)
            result.extend([node.val] * node.count)
            self._inorder_recursive(node.right, result)
    
    def preorder_traversal(self) -> List[int]:
        """Preorder traversal (root, left, right)"""
        result = []
        self._preorder_recursive(self.root, result)
        return result
    
    def _preorder_recursive(self, node: Optional[TreeNode], result: List[int]) -> None:
        """Helper for preorder traversal"""
        if node:
            result.extend([node.val] * node.count)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)
    
    def postorder_traversal(self) -> List[int]:
        """Postorder traversal (left, right, root)"""
        result = []
        self._postorder_recursive(self.root, result)
        return result
    
    def _postorder_recursive(self, node: Optional[TreeNode], result: List[int]) -> None:
        """Helper for postorder traversal"""
        if node:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.extend([node.val] * node.count)
    
    def level_order_traversal(self) -> List[List[int]]:
        """Level order traversal (breadth-first)"""
        if not self.root:
            return []
        
        result = []
        queue = deque([self.root])
        
        while queue:
            level_size = len(queue)
            level_values = []
            
            for _ in range(level_size):
                node = queue.popleft()
                level_values.extend([node.val] * node.count)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(level_values)
        
        return result
    
    # Tree Analysis Methods
    def height(self) -> int:
        """Calculate the height of the tree"""
        return self._height_recursive(self.root)
    
    def _height_recursive(self, node: Optional[TreeNode]) -> int:
        """Helper for height calculation"""
        if not node:
            return -1  # Height of empty tree is -1
        return 1 + max(self._height_recursive(node.left), 
                      self._height_recursive(node.right))
    
    def is_valid_bst(self) -> bool:
        """Validate if the tree maintains BST property"""
        return self._validate_bst(self.root, float('-inf'), float('inf'))
    
    def _validate_bst(self, node: Optional[TreeNode], min_val: float, max_val: float) -> bool:
        """Helper for BST validation"""
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (self._validate_bst(node.left, min_val, node.val) and 
                self._validate_bst(node.right, node.val, max_val))
    
    def is_balanced(self) -> bool:
        """Check if the tree is height-balanced"""
        def check_balance(node: Optional[TreeNode]) -> tuple[bool, int]:
            if not node:
                return True, -1
            
            left_balanced, left_height = check_balance(node.left)
            if not left_balanced:
                return False, 0
            
            right_balanced, right_height = check_balance(node.right)
            if not right_balanced:
                return False, 0
            
            balanced = abs(left_height - right_height) <= 1
            height = 1 + max(left_height, right_height)
            
            return balanced, height
        
        balanced, _ = check_balance(self.root)
        return balanced
    
    def get_range(self, low: int, high: int) -> List[int]:
        """Get all values in the given range [low, high]"""
        result = []
        self._range_search(self.root, low, high, result)
        return result
    
    def _range_search(self, node: Optional[TreeNode], low: int, high: int, result: List[int]) -> None:
        """Helper for range search"""
        if not node:
            return
        
        if low <= node.val <= high:
            result.extend([node.val] * node.count)
        
        if node.val > low:
            self._range_search(node.left, low, high, result)
        
        if node.val < high:
            self._range_search(node.right, low, high, result)
    
    def kth_smallest(self, k: int) -> Optional[int]:
        """Find the kth smallest element"""
        count = [0]
        return self._kth_smallest_helper(self.root, k, count)
    
    def _kth_smallest_helper(self, node: Optional[TreeNode], k: int, count: List[int]) -> Optional[int]:
        """Helper for kth smallest"""
        if not node:
            return None
        
        # Search in left subtree first
        left_result = self._kth_smallest_helper(node.left, k, count)
        if left_result is not None:
            return left_result
        
        # Process current node
        count[0] += node.count
        if count[0] >= k:
            return node.val
        
        # Search in right subtree
        return self._kth_smallest_helper(node.right, k, count)
    
    def path_to_node(self, val: int) -> List[int]:
        """Find the path from root to a given value"""
        path = []
        self._find_path(self.root, val, path)
        return path if path and path[-1] == val else []
    
    def _find_path(self, node: Optional[TreeNode], val: int, path: List[int]) -> bool:
        """Helper for finding path"""
        if not node:
            return False
        
        path.append(node.val)
        
        if node.val == val:
            return True
        
        if (node.val > val and self._find_path(node.left, val, path)) or \
           (node.val < val and self._find_path(node.right, val, path)):
            return True
        
        path.pop()
        return False
    
    def lowest_common_ancestor(self, val1: int, val2: int) -> Optional[int]:
        """Find the lowest common ancestor of two values"""
        if not self.search(val1) or not self.search(val2):
            return None
        
        return self._lca_recursive(self.root, val1, val2).val
    
    def _lca_recursive(self, node: TreeNode, val1: int, val2: int) -> TreeNode:
        """Helper for LCA"""
        if val1 < node.val and val2 < node.val:
            return self._lca_recursive(node.left, val1, val2)
        elif val1 > node.val and val2 > node.val:
            return self._lca_recursive(node.right, val1, val2)
        else:
            return node
    
    # Tree Statistics
    def get_statistics(self) -> dict:
        """Get comprehensive tree statistics"""
        if not self.root:
            return {"size": 0, "height": -1, "balanced": True, "valid_bst": True}
        
        return {
            "size": self.size,
            "height": self.height(),
            "balanced": self.is_balanced(),
            "valid_bst": self.is_valid_bst(),
            "min_value": self._find_min(self.root).val,
            "max_value": self._find_max(self.root).val,
            "leaf_count": self._count_leaves(self.root),
            "internal_nodes": self.size - self._count_leaves(self.root)
        }
    
    def _count_leaves(self, node: Optional[TreeNode]) -> int:
        """Count leaf nodes"""
        if not node:
            return 0
        if not node.left and not node.right:
            return 1
        return self._count_leaves(node.left) + self._count_leaves(node.right)
    
    # Tree Visualization
    def print_tree(self) -> None:
        """Print a visual representation of the tree"""
        if not self.root:
            print("Empty tree")
            return
        
        lines, *_ = self._display_aux(self.root)
        for line in lines:
            print(line)
    
    def _display_aux(self, node: Optional[TreeNode]) -> tuple[List[str], int, int, int]:
        """Auxiliary function for tree visualization"""
        if not node:
            return [], 0, 0, 0
        
        line1 = []
        line2 = []
        
        if not node.right and not node.left:
            width = len(str(node.val))
            height = 1
            middle = width // 2
            return [str(node.val)], width, height, middle
        
        if not node.right:
            lines, n, p, x = self._display_aux(node.left)
            s = str(node.val)
            u = len(s)
            first_line = s + x * ' ' + (n - x) * ' '
            second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
            shifted_lines = [u * ' ' + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2
        
        if not node.left:
            lines, n, p, x = self._display_aux(node.right)
            s = str(node.val)
            u = len(s)
            first_line = (x + 1) * ' ' + s
            second_line = x * ' ' + '/' + (u + n - x - 1) * ' '
            shifted_lines = [(x + u) * ' ' + line for line in lines]
            return [first_line, second_line] + shifted_lines, x + u + n, p + 2, x + u // 2
        
        left, n, p, x = self._display_aux(node.left)
        right, m, q, y = self._display_aux(node.right)
        s = str(node.val)
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s + y * '_' + (m - y) * ' '
        second_line = x * ' ' + '/' + (n - x - 1 + u + y) * ' ' + '\\' + (m - y - 1) * ' '
        
        if p < q:
            left += [n * ' '] * (q - p)
        elif q < p:
            right += [m * ' '] * (p - q)
        
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * ' ' + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2


def demonstrate_advanced_bst():
    """Comprehensive demonstration of BST operations"""
    print("🌳 ADVANCED BINARY SEARCH TREE DEMONSTRATION")
    print("=" * 50)
    
    # Create BST and insert values
    bst = AdvancedBST()
    values = [50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45]
    
    print("\n1. Building BST:")
    for val in values:
        bst.insert(val)
        print(f"Inserted {val}")
    
    print(f"\nTree structure:")
    bst.print_tree()
    
    # Basic operations
    print(f"\n2. Basic Operations:")
    print(f"Tree size: {bst.size}")
    print(f"Search 40: {bst.search(40)}")
    print(f"Search 99: {bst.search(99)}")
    
    # Traversals
    print(f"\n3. Traversals:")
    print(f"Inorder (sorted): {bst.inorder_traversal()}")
    print(f"Preorder: {bst.preorder_traversal()}")
    print(f"Postorder: {bst.postorder_traversal()}")
    print(f"Level order: {bst.level_order_traversal()}")
    
    # Advanced operations
    print(f"\n4. Advanced Operations:")
    print(f"Height: {bst.height()}")
    print(f"Is valid BST: {bst.is_valid_bst()}")
    print(f"Is balanced: {bst.is_balanced()}")
    print(f"Range [30, 60]: {bst.get_range(30, 60)}")
    print(f"3rd smallest: {bst.kth_smallest(3)}")
    print(f"Path to 45: {bst.path_to_node(45)}")
    print(f"LCA of 25 and 45: {bst.lowest_common_ancestor(25, 45)}")
    
    # Tree statistics
    print(f"\n5. Tree Statistics:")
    stats = bst.get_statistics()
    for key, value in stats.items():
        print(f"{key}: {value}")
    
    # Deletion demonstration
    print(f"\n6. Deletion Operations:")
    print(f"Before deletion: {bst.inorder_traversal()}")
    
    bst.delete(20)  # Delete leaf
    print(f"After deleting 20 (leaf): {bst.inorder_traversal()}")
    
    bst.delete(30)  # Delete node with two children
    print(f"After deleting 30 (two children): {bst.inorder_traversal()}")
    
    print(f"\nFinal tree structure:")
    bst.print_tree()


if __name__ == "__main__":
    demonstrate_advanced_bst()
    
    # Interactive demo
    print(f"\n{'='*50}")
    print("🎯 Perfect for Hacktoberfest 2024!")
    print("This implementation includes:")
    print("✅ Complete CRUD operations")
    print("✅ Advanced BST algorithms") 
    print("✅ Tree analysis and validation")
    print("✅ Multiple traversal methods")
    print("✅ Statistical analysis")
    print("✅ Tree visualization")
    print("Happy coding! 🚀")


# Example usage for testing
"""
# Create and use the BST
bst = AdvancedBST()

# Insert values
for val in [50, 30, 70, 20, 40, 60, 80]:
    bst.insert(val)

# Basic operations
print(bst.inorder_traversal())  # [20, 30, 40, 50, 60, 70, 80]
print(bst.search(40))          # TreeNode(40)
print(bst.height())            # 2
print(bst.is_balanced())       # True

# Advanced operations
print(bst.kth_smallest(3))     # 40
print(bst.get_range(35, 65))   # [40, 50, 60]
print(bst.lowest_common_ancestor(20, 40))  # 30

# Delete operations
bst.delete(20)
print(bst.inorder_traversal())  # [30, 40, 50, 60, 70, 80]
"""