class Node:
    """
    Represents a single node in the Binary Search Tree.
    """
    def __init__(self, value):
        self.value = value  # The node's data
        self.left = None    # Pointer to the left child node
        self.right = None   # Pointer to the right child node

    def __str__(self):
        # Helper for printing
        return f"Node({self.value})"


class BinarySearchTree:
    """
    The main class that manages the BST operations.
    """
    def __init__(self):
        self.root = None  # The tree is initially empty

    def insert(self, value):
        """
        Public method to insert a new value into the tree.
        """
        if self.root is None:
            # If the tree is empty, the new node is the root
            self.root = Node(value)
        else:
            # Otherwise, find the correct spot starting from the root
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        """
        Private recursive helper method to find where to insert.
        """
        if value < current_node.value:
            # --- Go Left ---
            if current_node.left is None:
                # If there's no left child, insert here
                current_node.left = Node(value)
            else:
                # Otherwise, keep going down the left subtree
                self._insert_recursive(current_node.left, value)
                
        elif value > current_node.value:
            # --- Go Right ---
            if current_node.right is None:
                # If there's no right child, insert here
                current_node.right = Node(value)
            else:
                # Otherwise, keep going down the right subtree
                self._insert_recursive(current_node.right, value)
        
        # else: value == current_node.value
        # This implementation ignores duplicates. You could also
        # choose to place them on the right.

    def search(self, value):
        """
        Public method to search for a value. Returns True or False.
        """
        return self._search_recursive(self.root, value)

    def _search_recursive(self, current_node, value):
        """
        Private recursive helper method to find a value.
        """
        # Base Cases:
        # 1. We reached the end of a branch (node is None)
        # 2. We found the value
        if current_node is None:
            return False
        if current_node.value == value:
            return True

        # Recursive Steps:
        if value < current_node.value:
            # Search the left subtree
            return self._search_recursive(current_node.left, value)
        else: # value > current_node.value
            # Search the right subtree
            return self._search_recursive(current_node.right, value)

    def inorder_traversal(self):
        """
        Prints the tree's values in sorted order (Left, Root, Right).
        """
        print("In-order traversal:")
        self._inorder_helper(self.root)
        print() # Add a newline at the end

    def _inorder_helper(self, node):
        """
        Private recursive helper for in-order traversal.
        """
        if node:
            self._inorder_helper(node.left)
            print(node.value, end=' ')
            self._inorder_helper(node.right)


# --- Example Usage ---
if __name__ == "__main__":
    
    # 1. Create a new BST
    bst = BinarySearchTree()
    
    # 2. Insert values
    # The root will be 50
    values = [50, 30, 70, 20, 40, 60, 80]
    for val in values:
        bst.insert(val)

    # 3. Print the sorted values
    # An in-order traversal of a BST always yields a sorted list.
    bst.inorder_traversal()
    
    # 4. Search for values
    print("Is 40 in the tree?", bst.search(40))
    print("Is 99 in the tree?", bst.search(99))
