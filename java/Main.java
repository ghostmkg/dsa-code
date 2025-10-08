/**
 * A driver class to demonstrate the functionality of BinaryTree and BinarySearchTree.
 */
public class Main {
    int data;
    Node left, right;
    
    public void  Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
    public void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }
    public void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }
    public static void main(String[] args) {
        System.out.println("--- Binary Tree Demonstration ---");
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);
        tree.root.left.left.right = new Node(8);
        tree.root.right.right.left = new Node(9);

        System.out.print("In-order traversal: ");
        tree.inOrder(tree.root);
        System.out.println("\n");

        tree.topView();
        tree.bottomView();
        tree.leftView();
        tree.rightView();
        
        System.out.println("\n--- Binary Search Tree Demonstration ---");
        BinarySearchTree bst = new BinarySearchTree();
        
        // Insert nodes
        bst.insert(50);
        bst.insert(30);
        bst.insert(20);
        bst.insert(40);
        bst.insert(70);
        bst.insert(60);
        bst.insert(80);

        System.out.print("In-order traversal of BST: ");
        bst.inOrder(bst.root);
        System.out.println();

        System.out.println("\nDelete 20");
        bst.delete(20);
        System.out.print("In-order traversal after deleting 20: ");
        bst.inOrder(bst.root);
        System.out.println();

        System.out.println("\nDelete 30");
        bst.delete(30);
        System.out.print("In-order traversal after deleting 30: ");
        bst.inOrder(bst.root);
        System.out.println();

        System.out.println("\nDelete 50");
        bst.delete(50);
        System.out.print("In-order traversal after deleting 50: ");
        bst.inOrder(bst.root);
        System.out.println();

        System.out.println("\nBST Views:");
        bst.topView();
        bst.bottomView();
    }
}
