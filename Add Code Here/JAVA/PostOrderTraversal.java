class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class PostorderTraversal {

    // Recursive postorder traversal: Left → Right → Root
    void postOrder(Node node) {
        if (node == null)
            return;

        // Traverse left subtree
        postOrder(node.left);
        // Traverse right subtree
        postOrder(node.right);
        // Visit node
        System.out.print(node.data + " ");
    }

    public static void main(String[] args) {
        PostorderTraversal tree = new PostorderTraversal();

        // Build sample tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        System.out.println("Postorder traversal of binary tree:");
        tree.postOrder(root);
    }
}
