// lruCache.ts
// Simple LRU (Least Recently Used) Cache implementation in TypeScript

class LRUCache<K, V> {
    private capacity: number;
    private cache: Map<K, V>;

    constructor(capacity: number) {
        this.capacity = capacity;
        this.cache = new Map();
    }

    get(key: K): V | undefined {
        if (!this.cache.has(key)) return undefined;
        const value = this.cache.get(key)!;
        this.cache.delete(key);
        this.cache.set(key, value);
        return value;
    }

    put(key: K, value: V): void {
        if (this.cache.has(key)) {
            this.cache.delete(key);
        } else if (this.cache.size >= this.capacity) {
            const oldestKey = this.cache.keys().next().value;
            this.cache.delete(oldestKey);
        }
        this.cache.set(key, value);
    }
}

// Example usage
const lru = new LRUCache<string, number>(3);
lru.put('a', 1);
lru.put('b', 2);
lru.put('c', 3);
console.log(lru.get('a')); // 1
lru.put('d', 4); // 'b' is evicted
console.log(lru.get('b')); // undefined
console.log(lru.get('c')); // 3
