class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None
    
    def get_height(self, node):
        if not node:
            return 0
        return node.height
    
    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)
    
    def update_height(self, node):
        if not node:
            return
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
    
    def rotate_right(self, z):
        y = z.left
        T3 = y.right
        
        y.right = z
        z.left = T3
        
        self.update_height(z)
        self.update_height(y)
        
        return y
    
    def rotate_left(self, z):
        y = z.right
        T2 = y.left
        
        y.left = z
        z.right = T2
        
        self.update_height(z)
        self.update_height(y)
        
        return y
    
    def insert(self, key):
        self.root = self._insert(self.root, key)
    
    def _insert(self, node, key):
        if not node:
            return Node(key)
        
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        else:
            return node
        
        self.update_height(node)
        
        balance = self.get_balance(node)
        
        if balance > 1 and key < node.left.key:
            return self.rotate_right(node)
        
        if balance < -1 and key > node.right.key:
            return self.rotate_left(node)
        
        if balance > 1 and key > node.left.key:
            node.left = self.rotate_left(node.left)
            return self.rotate_right(node)
        
        if balance < -1 and key < node.right.key:
            node.right = self.rotate_right(node.right)
            return self.rotate_left(node)
        
        return node
    
    def delete(self, key):
        self.root = self._delete(self.root, key)
    
    def _delete(self, node, key):
        if not node:
            return node
        
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left
            
            temp = self._get_min_value_node(node.right)
            node.key = temp.key
            node.right = self._delete(node.right, temp.key)
        
        if not node:
            return node
        
        self.update_height(node)
        
        balance = self.get_balance(node)
        
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.rotate_right(node)
        
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.rotate_left(node.left)
            return self.rotate_right(node)
        
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.rotate_left(node)
        
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.rotate_right(node.right)
            return self.rotate_left(node)
        
        return node
    
    def _get_min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current
    
    def search(self, key):
        return self._search(self.root, key)
    
    def _search(self, node, key):
        if not node or node.key == key:
            return node
        
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)
    
    def inorder(self):
        result = []
        self._inorder(self.root, result)
        return result
    
    def _inorder(self, node, result):
        if node:
            self._inorder(node.left, result)
            result.append(node.key)
            self._inorder(node.right, result)
    
    def preorder(self):
        result = []
        self._preorder(self.root, result)
        return result
    
    def _preorder(self, node, result):
        if node:
            result.append(node.key)
            self._preorder(node.left, result)
            self._preorder(node.right, result)
    
    def postorder(self):
        result = []
        self._postorder(self.root, result)
        return result
    
    def _postorder(self, node, result):
        if node:
            self._postorder(node.left, result)
            self._postorder(node.right, result)
            result.append(node.key)
    
    def level_order(self):
        if not self.root:
            return []
        
        result = []
        queue = [self.root]
        
        while queue:
            node = queue.pop(0)
            result.append(node.key)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return result
    
    def get_max_depth(self):
        return self.get_height(self.root)
    
    def is_balanced(self):
        return self._is_balanced(self.root)
    
    def _is_balanced(self, node):
        if not node:
            return True
        
        balance = self.get_balance(node)
        if abs(balance) > 1:
            return False
        
        return self._is_balanced(node.left) and self._is_balanced(node.right)

if __name__ == "__main__":
    avl = AVLTree()
    
    elements = [50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 65]
    
    print("Inserting elements:", elements)
    for elem in elements:
        avl.insert(elem)
    
    print("\nInorder Traversal:", avl.inorder())
    print("Preorder Traversal:", avl.preorder())
    print("Postorder Traversal:", avl.postorder())
    print("Level Order Traversal:", avl.level_order())
    
    print("\nTree Height:", avl.get_max_depth())
    print("Is Balanced:", avl.is_balanced())
    
    search_key = 27
    found = avl.search(search_key)
    print(f"\nSearching for {search_key}:", "Found" if found else "Not Found")
    
    delete_elements = [10, 25, 75]
    print(f"\nDeleting elements: {delete_elements}")
    for elem in delete_elements:
        avl.delete(elem)
    
    print("Inorder after deletion:", avl.inorder())
    print("Is still balanced:", avl.is_balanced())
