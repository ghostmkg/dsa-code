/**
 * LRU (Least Recently Used) Cache Implementation
 * 
 * A fixed-size cache that removes the least recently used items when full.
 * Supports O(1) get and put operations using HashMap + Doubly Linked List.
 * 
 * Time Complexity:
 * - get: O(1)
 * - put: O(1)
 * 
 * Space Complexity: O(capacity)
 * 
 * Real-world Applications:
 * - CPU cache management
 * - Database query caching
 * - Web browser cache
 * - Redis/Memcached
 */

class ListNode {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    /**
     * @param {number} capacity - Maximum number of items cache can hold
     */
    constructor(capacity) {
        this.capacity = capacity;
        this.cache = new Map(); // Hash map for O(1) access
        this.size = 0;
        
        // Dummy head and tail for the doubly linked list
        this.head = new ListNode(0, 0); // Most recently used
        this.tail = new ListNode(0, 0); // Least recently used
        
        // Initialize empty list
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    /**
     * Get value by key and mark as most recently used
     * @param {number} key
     * @return {number} value or -1 if not found
     */
    get(key) {
        if (!this.cache.has(key)) {
            return -1;
        }
        
        const node = this.cache.get(key);
        this._moveToHead(node); // Mark as recently used
        return node.value;
    }

    /**
     * Add or update key-value pair
     * @param {number} key
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        if (this.cache.has(key)) {
            // Update existing key
            const node = this.cache.get(key);
            node.value = value;
            this._moveToHead(node);
        } else {
            // Add new key
            const newNode = new ListNode(key, value);
            this.cache.set(key, newNode);
            this._addNode(newNode);
            this.size++;
            
            // Evict if over capacity
            if (this.size > this.capacity) {
                const tail = this._popTail();
                this.cache.delete(tail.key);
                this.size--;
            }
        }
    }

    /**
     * Remove least recently used item
     * @return {ListNode} removed node
     */
    _popTail() {
        const tail = this.tail.prev;
        this._removeNode(tail);
        return tail;
    }

    /**
     * Move node to head (most recently used position)
     * @param {ListNode} node
     */
    _moveToHead(node) {
        this._removeNode(node);
        this._addNode(node);
    }

    /**
     * Remove node from linked list
     * @param {ListNode} node
     */
    _removeNode(node) {
        const prev = node.prev;
        const next = node.next;
        
        prev.next = next;
        next.prev = prev;
    }

    /**
     * Add node to head (most recently used position)
     * @param {ListNode} node
     */
    _addNode(node) {
        node.prev = this.head;
        node.next = this.head.next;
        
        this.head.next.prev = node;
        this.head.next = node;
    }

    /**
     * Get current cache size
     * @return {number}
     */
    getSize() {
        return this.size;
    }

    /**
     * Get all cache entries in MRU to LRU order
     * @return {Array} Array of [key, value] pairs
     */
    getEntries() {
        const entries = [];
        let current = this.head.next;
        
        while (current !== this.tail) {
            entries.push([current.key, current.value]);
            current = current.next;
        }
        
        return entries;
    }

    /**
     * Clear the entire cache
     */
    clear() {
        this.cache.clear();
        this.size = 0;
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    /**
     * Get cache statistics
     * @return {Object} Cache metrics
     */
    getStats() {
        return {
            size: this.size,
            capacity: this.capacity,
            usage: `${this.size}/${this.capacity}`,
            isFull: this.size === this.capacity
        };
    }
}

// Example Usage and Demonstration
function demonstrateLRUCache() {
    console.log("=== LRU Cache Demonstration ===\n");
    
    // Create cache with capacity 3
    const cache = new LRUCache(3);
    
    console.log("1. Initializing cache with capacity 3");
    console.log("Cache stats:", cache.getStats());
    
    // Test sequence
    console.log("\n2. Adding items:");
    cache.put(1, "A");
    cache.put(2, "B");
    cache.put(3, "C");
    console.log("After adding 3 items:", cache.getEntries());
    console.log("Cache stats:", cache.getStats());
    
    console.log("\n3. Access pattern:");
    console.log("Get key 2:", cache.get(2)); // B (moves 2 to MRU)
    console.log("Get key 1:", cache.get(1)); // A (moves 1 to MRU)
    console.log("Current order:", cache.getEntries());
    
    console.log("\n4. Adding 4th item (should evict LRU):");
    cache.put(4, "D");
    console.log("After adding 4th item:", cache.getEntries());
    console.log("Key 3 should be evicted (LRU)");
    
    console.log("\n5. Update existing key:");
    cache.put(2, "B-UPDATED");
    console.log("After updating key 2:", cache.getEntries());
    
    console.log("\n6. Get non-existent key:");
    console.log("Get key 5:", cache.get(5)); // -1 (not found)
    
    console.log("\n7. Final cache state:");
    console.log("Entries:", cache.getEntries());
    console.log("Stats:", cache.getStats());
}

// Advanced Example: Browser Cache Simulation
class BrowserCache extends LRUCache {
    constructor(capacity) {
        super(capacity);
        this.hits = 0;
        this.misses = 0;
    }
    
    get(key) {
        const result = super.get(key);
        if (result !== -1) {
            this.hits++;
        } else {
            this.misses++;
        }
        return result;
    }
    
    getHitRate() {
        const total = this.hits + this.misses;
        return total > 0 ? (this.hits / total * 100).toFixed(2) + '%' : '0%';
    }
    
    getStats() {
        const baseStats = super.getStats();
        return {
            ...baseStats,
            hits: this.hits,
            misses: this.misses,
            hitRate: this.getHitRate()
        };
    }
}

function demonstrateBrowserCache() {
    console.log("\n\n=== Browser Cache Simulation ===");
    
    const browserCache = new BrowserCache(2);
    const requests = ['home', 'about', 'home', 'contact', 'about', 'home', 'products'];
    
    console.log("Cache capacity: 2");
    console.log("Request sequence:", requests);
    console.log("\nProcessing requests:");
    
    requests.forEach((page, i) => {
        const result = browserCache.get(page);
        if (result === -1) {
            console.log(`Request ${i + 1}: '${page}' - MISS - loading from server`);
            browserCache.put(page, `Content for ${page}`);
        } else {
            console.log(`Request ${i + 1}: '${page}' - HIT - served from cache`);
        }
    });
    
    console.log("\nFinal cache state:", browserCache.getEntries());
    console.log("Performance stats:", browserCache.getStats());
}

// Run demonstrations
if (require.main === module) {
    demonstrateLRUCache();
    demonstrateBrowserCache();
}

module.exports = { LRUCache, BrowserCache };