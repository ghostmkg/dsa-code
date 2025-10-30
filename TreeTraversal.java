// Tree Traversal Demo
class TreeTraversal {
    
    // Each node of the tree
    static class Node {
        int data;
        Node left, right;
        
        Node(int value) {
            data = value;
            left = right = null;
        }
    }

    //  Inorder Traversal (Left → Root → Right)
    void inorder(Node node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    // Preorder Traversal (Root → Left → Right)
    void preorder(Node node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    // Postorder Traversal (Left → Right → Root)
    void postorder(Node node) {
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    public static void main(String[] args) {
        TreeTraversal tree = new TreeTraversal();
        
        // Let’s grow a lil binary tree 🌸
        //        1
        //       / \
        //      2   3
        //     / \
        //    4   5
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        System.out.println("🌱 Inorder traversal:");
        tree.inorder(root);
        System.out.println("\n🌿 Preorder traversal:");
        tree.preorder(root);
        System.out.println("\n🌳 Postorder traversal:");
        tree.postorder(root);
    }
}
