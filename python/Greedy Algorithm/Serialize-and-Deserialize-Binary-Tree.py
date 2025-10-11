#Using Preorder Traversal with Null Markers
    
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def preorder(node):
            if not node:
                return ["null"]
            return [str(node.val)] + preorder(node.left) + preorder(node.right)
        
        return ",".join(preorder(root))
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(",")
        self.index = 0
        
        def build_tree():
            if self.index >= len(nodes) or nodes[self.index] == "null":
                self.index += 1
                return None
            
            node = TreeNode(int(nodes[self.index]))
            self.index += 1
            node.left = build_tree()
            node.right = build_tree()
            return node
        
        return build_tree()

# Alternative: Using iterative BFS approach
class CodecBFS:
    def serialize(self, root):
        """Encodes a tree to a single string using BFS."""
        if not root:
            return ""
        
        queue = collections.deque([root])
        result = []
        
        while queue:
            node = queue.popleft()
            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("null")
        
        return ",".join(result)
    
    def deserialize(self, data):
        """Decodes your encoded data to tree using BFS."""
        if not data:
            return None
        
        nodes = data.split(",")
        root = TreeNode(int(nodes[0]))
        queue = collections.deque([root])
        index = 1
        
        while queue and index < len(nodes):
            node = queue.popleft()
            
            # Left child
            if nodes[index] != "null":
                node.left = TreeNode(int(nodes[index]))
                queue.append(node.left)
            index += 1
            
            # Right child
            if index < len(nodes) and nodes[index] != "null":
                node.right = TreeNode(int(nodes[index]))
                queue.append(node.right)
            index += 1
        
        return root