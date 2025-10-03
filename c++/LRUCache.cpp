/**
 * @file LRUCache.cpp
 * @brief Implementation of LRU (Least Recently Used) Cache
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Design a data structure that follows the constraints of Least Recently Used (LRU) cache.
 *
 * Operations:
 * - get(key): Return the value of the key if it exists, otherwise return -1
 * - put(key, value): Update the value if key exists, otherwise add the key-value pair
 *   If the cache reaches capacity, evict the least recently used key before inserting
 *
 * Algorithm: Doubly Linked List + Hash Map
 * - Hash map stores key -> node pointer for O(1) access
 * - Doubly linked list maintains order (most recent at head, least recent at tail)
 * - Move accessed/added nodes to head
 * - Remove from tail when capacity exceeded
 *
 * Time Complexity: O(1) for both get and put operations
 * Space Complexity: O(capacity)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Node structure for doubly linked list
 */
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

/**
 * @brief LRU Cache implementation using HashMap and Doubly Linked List
 */
class LRUCache {
private:
    int capacity;                           // Maximum capacity of cache
    unordered_map<int, Node*> cache;        // Hash map: key -> node pointer
    Node* head;                             // Dummy head (most recently used)
    Node* tail;                             // Dummy tail (least recently used)

    /**
     * @brief Add node right after head (mark as most recently used)
     * @param node Node to be added
     */
    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    /**
     * @brief Remove a node from the linked list
     * @param node Node to be removed
     */
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    /**
     * @brief Move a node to head (mark as most recently used)
     * @param node Node to be moved
     */
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    /**
     * @brief Remove the least recently used node (node before tail)
     * @return Pointer to the removed node
     */
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    /**
     * @brief Constructor to initialize LRU cache with given capacity
     * @param capacity Maximum number of items cache can hold
     */
    LRUCache(int capacity) : capacity(capacity) {
        // Create dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    /**
     * @brief Get value for a given key
     * @param key The key to search for
     * @return Value if key exists, -1 otherwise
     */
    int get(int key) {
        // Check if key exists in cache
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }

        // Key found - move to head (mark as recently used)
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    /**
     * @brief Put a key-value pair into cache
     * @param key The key to insert/update
     * @param value The value to store
     */
    void put(int key, int value) {
        // Check if key already exists
        if (cache.find(key) != cache.end()) {
            // Update existing key
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);  // Mark as recently used
        } else {
            // Add new key-value pair
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);  // Add to head

            // Check if capacity exceeded
            if (cache.size() > capacity) {
                // Remove least recently used item
                Node* lruNode = popTail();
                cache.erase(lruNode->key);
                delete lruNode;
            }
        }
    }

    /**
     * @brief Destructor to free memory
     */
    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Display current cache contents (for debugging)
     */
    void display() {
        cout << "Cache contents (MRU -> LRU): ";
        Node* current = head->next;
        while (current != tail) {
            cout << "(" << current->key << ":" << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    // Create LRU Cache with capacity 2
    LRUCache cache(2);

    cout << "=== LRU Cache Operations ===" << endl;

    // Test sequence
    cache.put(1, 1);
    cout << "put(1, 1)" << endl;
    cache.display();

    cache.put(2, 2);
    cout << "put(2, 2)" << endl;
    cache.display();

    cout << "get(1): " << cache.get(1) << endl;  // Returns 1
    cache.display();

    cache.put(3, 3);  // Evicts key 2
    cout << "put(3, 3) - evicts key 2" << endl;
    cache.display();

    cout << "get(2): " << cache.get(2) << endl;  // Returns -1 (not found)

    cache.put(4, 4);  // Evicts key 1
    cout << "put(4, 4) - evicts key 1" << endl;
    cache.display();

    cout << "get(1): " << cache.get(1) << endl;  // Returns -1 (not found)
    cout << "get(3): " << cache.get(3) << endl;  // Returns 3
    cout << "get(4): " << cache.get(4) << endl;  // Returns 4

    return 0;
}
