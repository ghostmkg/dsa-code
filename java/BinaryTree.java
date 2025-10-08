import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
/**

 * BinaryTree class: Implements generic Binary Tree operations, including
 * standard traversals and utility methods for computing different tree views.
 */
public class BinaryTree {

    // --- 1. Standard Tree Node Definition ---
    public static class Node {
        int data;
        Node left;
        Node right;

        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Root of the tree
    public Node root;

    public BinaryTree() {
        this.root = null;
    }

    // --- 2. Traversal Methods ---

    public void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }

    public void preorder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preorder(node.left);
            preorder(node.right);
        }
    }

    public void postorder(Node node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);

 /* Represents a single node in a binary tree.
 */
class Node {
    int data;
    Node left;
    Node right;

    /**
     * Constructor to create a new node.
     * @param data The data to be stored in the node.
     */
    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

/**
 * Implements a Binary Tree and includes methods for traversal and different views.
 */
public class  BinaryTree {
    Node root;

    public void BinaryTree(Node root) {
        root = null;
    }

    /**
     * Performs an in-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }

    /**
     * Performs a pre-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    /**
     * Performs a post-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void postOrder(Node node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);

            System.out.print(node.data + " ");
        }
    }

    // --- 3. View Methods (Utility) ---

    // Top View: Nodes visible when looking from the top (first node encountered at each Horizontal Distance)
    public List<Integer> topView() {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map stores <Horizontal Distance, Node Data>
        Map<Integer, Integer> map = new TreeMap<>();
        // Queue stores <Node, Horizontal Distance>
        Queue<Pair<Node, Integer>> queue = new LinkedList<>();

        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<Node, Integer> current = queue.poll();
            Node node = current.key;
            int hd = current.value;

            // Only update if this HD is encountered for the first time (this is the 'top' node)
            if (!map.containsKey(hd)) {
                map.put(hd, node.data);
            }

            if (node.left != null) {
                queue.add(new Pair<>(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.add(new Pair<>(node.right, hd + 1));
            }
        }
        
        // Add all values from the sorted map (TreeMap ensures HD is sorted) to the result list
        result.addAll(map.values());
        return result;
    }

    // Bottom View: Nodes visible when looking from the bottom (last node encountered at each Horizontal Distance)
    public List<Integer> bottomView() {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map stores <Horizontal Distance, Node Data>
        Map<Integer, Integer> map = new TreeMap<>();
        // Queue stores <Node, Horizontal Distance>
        Queue<Pair<Node, Integer>> queue = new LinkedList<>();

        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<Node, Integer> current = queue.poll();
            Node node = current.key;
            int hd = current.value;

            // Always update the map. The last node processed for a given HD in BFS 
            // will be the lowest/closest to the bottom at that HD.
            map.put(hd, node.data);

            if (node.left != null) {
                queue.add(new Pair<>(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.add(new Pair<>(node.right, hd + 1));
            }
        }

        result.addAll(map.values());
        return result;
    }
    
    // Left View: The first node of every level
    public List<Integer> leftView() {
        List<Integer> result = new ArrayList<>();
        leftView(root, 1, new int[]{0}, result);
        return result;
    }

    // Recursive helper for Left View
    private void leftView(Node node, int level, int[] maxLevel, List<Integer> result) {
        if (node == null) return;

        // If this is the first node at the current level, add it to the view
        if (maxLevel[0] < level) {
            result.add(node.data);
            maxLevel[0] = level;
        }

        // Recurse left first to ensure the leftmost node is processed first
        leftView(node.left, level + 1, maxLevel, result);
        leftView(node.right, level + 1, maxLevel, result);
    }

    // Right View: The last node of every level
    public List<Integer> rightView() {
        List<Integer> result = new ArrayList<>();
        rightView(root, 1, new int[]{0}, result);
        return result;
    }
    
    // Recursive helper for Right View
    private void rightView(Node node, int level, int[] maxLevel, List<Integer> result) {
        if (node == null) return;

        // If this is the first node at the current level, add it to the view
        if (maxLevel[0] < level) {
            result.add(node.data);
            maxLevel[0] = level;
        }

        // Recurse right first to ensure the rightmost node is processed first
        rightView(node.right, level + 1, maxLevel, result);
        rightView(node.left, level + 1, maxLevel, result);
    }

    // Helper class for combining Node and Horizontal Distance in the Queue (for Top/Bottom View)
    private static class Pair<K, V> {
        K key;
        V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

    /**
     * Computes and prints the top view of the binary tree.
     * The top view consists of the nodes that are visible from the top.
     */
    public void topView() {
        if (root == null) {
            return;
        }
    }
        class QueueObj {
            Node node;
            int hd; // Horizontal Distance

            QueueObj(Node node, int hd) {
                this.node = node;
                this.hd = hd;
            }
        }

        Queue<QueueObj> q = new LinkedList<>();
        Map<Integer, Node> topViewMap = new TreeMap<>();

        q.add(new QueueObj(root, 0));

        while (!q.isEmpty()) {
            QueueObj tmpNode = q.poll();
            if (!topViewMap.containsKey(tmpNode.hd)) {
                topViewMap.put(tmpNode.hd, tmpNode.node);
            }

            if (tmpNode.node.left != null) {
                q.add(new QueueObj(tmpNode.node.left, tmpNode.hd - 1));
            }
            if (tmpNode.node.right != null) {
                q.add(new QueueObj(tmpNode.node.right, tmpNode.hd + 1));
            }
        }
        System.out.println("Top View:");
        for (Map.Entry<Integer, Node> entry : topViewMap.entrySet()) {
            System.out.print(entry.getValue().data + " ");
        }
        System.out.println();
    }

    /**
     * Computes and prints the bottom view of the binary tree.
     * The bottom view consists of the nodes that are visible from the bottom.
     */
    public void bottomView() {
        if (root == null) {
            return;
        }

        class QueueObj {
            Node node;
            int hd; // Horizontal Distance

            QueueObj(Node node, int hd) {
                this.node = node;
                this.hd = hd;
            }
        }

        Queue<QueueObj> q = new LinkedList<>();
        Map<Integer, Node> bottomViewMap = new TreeMap<>();

        q.add(new QueueObj(root, 0));

        while (!q.isEmpty()) {
            QueueObj tmpNode = q.poll();
            bottomViewMap.put(tmpNode.hd, tmpNode.node);

            if (tmpNode.node.left != null) {
                q.add(new QueueObj(tmpNode.node.left, tmpNode.hd - 1));
            }
            if (tmpNode.node.right != null) {
                q.add(new QueueObj(tmpNode.node.right, tmpNode.hd + 1));
            }
        }
        System.out.println("Bottom View:");
        for (Map.Entry<Integer, Node> entry : bottomViewMap.entrySet()) {
            System.out.print(entry.getValue().data + " ");
        }
        System.out.println();
    }

    /**
     * Computes and prints the left view of the binary tree.
     * The left view consists of the first node at each level.
     */
    public void leftView() {
        if (root == null) {
            return;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        System.out.println("Left View:");
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 1; i <= n; i++) {
                Node temp = queue.poll();
                if (i == 1) {
                    System.out.print(temp.data + " ");
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
        System.out.println();
    }

    /**
     * Computes and prints the right view of the binary tree.
     * The right view consists of the last node at each level.
     */
    public void rightView() {
        if (root == null) {
            return;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        System.out.println("Right View:");
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 1; i <= n; i++) {
                Node temp = queue.poll();
                if (i == n) {
                    System.out.print(temp.data + " ");
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
        System.out.println();

    }
}
