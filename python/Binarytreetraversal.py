# Define a tree node
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# Inorder traversal function
def inorder(root):
    if root:
        inorder(root.left)
        print(root.value, end=' ')
        inorder(root.right)

# Build a simple tree
#       10
#      /  \
#     5    15
#         /  \
#        12   20

root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.right.left = Node(12)
root.right.right = Node(20)

# Traverse tree
print("Inorder Traversal:")
inorder(root)
