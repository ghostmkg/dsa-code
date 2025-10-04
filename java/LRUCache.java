import java.util.HashMap;
import java.util.Map;

/**
 * An implementation of a Least Recently Used (LRU) Cache.
 *
 * This data structure uses a combination of a HashMap and a Doubly Linked List
 * to achieve O(1) average time complexity for both `get` and `put` operations.
 *
 * - The HashMap stores the key and a reference to the Node in the linked list
 * for O(1) lookup.
 * - The Doubly Linked List maintains the order of usage. The most recently used
 * item is at the head, and the least recently used item is at the tail.
 */
public class LRUCache {

  // Inner class to represent a node in the doubly linked list.
  private static class Node {
    int key;
    int value;
    Node prev;
    Node next;

    Node(int key, int value) {
      this.key = key;
      this.value = value;
    }
  }

  private final int capacity;
  private final Map<Integer, Node> map;
  // Dummy head and tail nodes to simplify list operations (add/remove).
  private final Node head;
  private final Node tail;

  /**
   * Constructs an LRUCache with a given capacity.
   * 
   * @param capacity The maximum number of items the cache can hold.
   */
  public LRUCache(int capacity) {
    this.capacity = capacity;
    this.map = new HashMap<>();
    this.head = new Node(0, 0); // Dummy head
    this.tail = new Node(0, 0); // Dummy tail
    head.next = tail;
    tail.prev = head;
  }

  /**
   * Retrieves the value for a given key.
   * If the key exists, the item is marked as recently used by moving it to the
   * head of the list.
   * 
   * @param key The key to look up.
   * @return The value associated with the key, or -1 if the key does not exist.
   */
  public int get(int key) {
    if (!map.containsKey(key)) {
      return -1;
    }
    Node node = map.get(key);
    // This item is now the most recently used, so move it to the head.
    removeNode(node);

    addToHead(node);
    return node.value;
  }

  /**
   * Inserts or updates a key-value pair.
   * If the key already exists, its value is updated, and it's marked as recently
   * used.
   * If it's a new key and the cache is full, the least recently used item is
   * evicted.
   * 
   * @param key   The key to insert or update.
   * @param value The value to associate with the key.
   */
  public void put(int key, int value) {
    // If the key already exists, update its value and move it to the head.
    if (map.containsKey(key)) {
      Node node = map.get(key);
      node.value = value;
      removeNode(node);
      addToHead(node);
      return;
    }

    // If the cache is full, evict the least recently used item (at the tail).
    if (map.size() == capacity) {
      Node tailPrev = tail.prev;
      removeNode(tailPrev);
      map.remove(tailPrev.key);
    }

    // Add the new item to the head of the list and to the map.
    Node newNode = new Node(key, value);
    addToHead(newNode);
    map.put(key, newNode);
  }

  // Helper method to add a node to the front (head) of the list.
  private void addToHead(Node node) {
    node.next = head.next;
    head.next.prev = node;
    head.next = node;
    node.prev = head;
  }

  // Helper method to remove a node from its current position in the list.
  private void removeNode(Node node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }

  // Main method to demonstrate usage.
  public static void main(String[] args) {
    System.out.println("Initializing LRUCache with capacity 2...");
    LRUCache cache = new LRUCache(2);

    System.out.println("put(1, 1)");
    cache.put(1, 1);
    System.out.println("put(2, 2)");
    cache.put(2, 2);

    System.out.println("get(1): " + cache.get(1)); // returns 1, (1,1) is now most recently used

    System.out.println("put(3, 3)"); // evicts key 2, (3,3) is now most recently used
    cache.put(3, 3);

    System.out.println("get(2): " + cache.get(2)); // returns -1 (not found)

    System.out.println("put(4, 4)"); // evicts key 1, (4,4) is now most recently used
    cache.put(4, 4);

    System.out.println("get(1): " + cache.get(1)); // returns -1 (not found)
    System.out.println("get(3): " + cache.get(3)); // returns 3
    System.out.println("get(4): " + cache.get(4)); // returns 4
  }
}