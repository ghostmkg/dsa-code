import java.util.*;

// Node class
class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }

    Node(int i) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    Node(int i) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}

class BinaryTreeViews {
    Node root;

    BinaryTreeViews() {
        root = null;
    }

    // Preorder
    void preorder(Node node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    // Inorder
    void inorder(Node node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    // Postorder
    void postorder(Node node) {
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    // Level-order
    void levelOrder() {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node temp = q.poll();
            System.out.print(temp.data + " ");
            if (temp.left != null) q.add(temp.left);
            if (temp.right != null) q.add(temp.right);
        }
    }

    // Left View
    void leftView() {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 1; i <= n; i++) {
                Node temp = q.poll();
                if (i == 1) System.out.print(temp.data + " ");
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }
        }
    }

    // Right View
    void rightView() {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 1; i <= n; i++) {
                Node temp = q.poll();
                if (i == n) System.out.print(temp.data + " ");
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }
        }
    }

    // Top View
    void topView() {
        if (root == null) return;
        class Pair {
            Node node;
            int hd;
            Pair(Node n, int h) { node = n; hd = h; }
        }
        Queue<Pair> q = new LinkedList<>();
        Map<Integer, Integer> map = new TreeMap<>();
        q.add(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            if (!map.containsKey(p.hd)) map.put(p.hd, p.node.data);
            if (p.node.left != null) q.add(new Pair(p.node.left, p.hd - 1));
            if (p.node.right != null) q.add(new Pair(p.node.right, p.hd + 1));
        }
        for (int val : map.values()) System.out.print(val + " ");
    }

    // Bottom View
    void bottomView() {
        if (root == null) return;
        class Pair {
            Node node;
            int hd;
            Pair(Node n, int h) { node = n; hd = h; }
        }
        Queue<Pair> q = new LinkedList<>();
        Map<Integer, Integer> map = new TreeMap<>();
        q.add(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            map.put(p.hd, p.node.data);
            if (p.node.left != null) q.add(new Pair(p.node.left, p.hd - 1));
            if (p.node.right != null) q.add(new Pair(p.node.right, p.hd + 1));
        }
        for (int val : map.values()) System.out.print(val + " ");
    }
}

// Demo
public class BinaryTreeDemo {
    public static void main(String[] args) {
        BinaryTreeViews bt = new BinaryTreeViews();
        bt.root = new Node(1);
        bt.root.left = new Node(2);
        bt.root.right = new Node(3);
        bt.root.left.left = new Node(4);
        bt.root.left.right = new Node(5);
        bt.root.right.right = new Node(6);
        bt.root.right.left = new Node(7);

        System.out.println("Binary Tree Views:");
        System.out.print("Preorder: "); bt.preorder(bt.root); System.out.println();
        System.out.print("Inorder: "); bt.inorder(bt.root); System.out.println();
        System.out.print("Postorder: "); bt.postorder(bt.root); System.out.println();
        System.out.print("Level-order: "); bt.levelOrder(); System.out.println();
        System.out.print("Left View: "); bt.leftView(); System.out.println();
        System.out.print("Right View: "); bt.rightView(); System.out.println();
        System.out.print("Top View: "); bt.topView(); System.out.println();
        System.out.print("Bottom View: "); bt.bottomView(); System.out.println();
    }
}
