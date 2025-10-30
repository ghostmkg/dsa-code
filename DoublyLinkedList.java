import java.util.NoSuchElementException;

public class DoublyLinkedList {

    /**
     * Private inner class to represent a node in the list.
     * It holds the data, a reference to the next node, and a reference to the previous node.
     */
    private class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
            this.next = null; // Initially null
            this.prev = null; // Initially null
        }
    }

    // --- List Attributes ---
    private Node head; // Pointer to the first node
    private Node tail; // Pointer to the last node
    private int size;  // Number of nodes in the list

    /**
     * Constructor for an empty DoublyLinkedList.
     */
    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // --- Core Methods ---

    /**
     * Checks if the list is empty.
     * @return true if the list has 0 elements, false otherwise.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Returns the number of elements in the list.
     * @return the size of the list.
     */
    public int getSize() {
        return size;
    }

    /**
     * Adds a new node to the front (head) of the list.
     * @param data The data for the new node.
     */
    public void addFirst(int data) {
        Node newNode = new Node(data);

        if (isEmpty()) {
            // If list is empty, new node is both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // 1. Link new node to the old head
            newNode.next = head;
            // 2. Link old head back to the new node
            head.prev = newNode;
            // 3. Move head pointer to the new node
            head = newNode;
        }
        size++;
    }

    /**
     * Adds a new node to the end (tail) of the list.
     * @param data The data for the new node.
     */
    public void addLast(int data) {
        Node newNode = new Node(data);

        if (isEmpty()) {
            // If list is empty, new node is both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // 1. Link old tail to the new node
            tail.next = newNode;
            // 2. Link new node back to the old tail
            newNode.prev = tail;
            // 3. Move tail pointer to the new node
            tail = newNode;
        }
        size++;
    }

    /**
     * Removes and returns the first node (head) from the list.
     * @return The data of the removed node.
     * @throws NoSuchElementException if the list is empty.
     */
    public int removeFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException("Cannot remove from an empty list.");
        }

        int data = head.data;

        if (head == tail) {
            // Case 1: Only one node in the list
            head = null;
            tail = null;
        } else {
