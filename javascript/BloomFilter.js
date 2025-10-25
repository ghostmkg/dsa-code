/**
 * Bloom Filter - Probabilistic Data Structure
 * 
 * A space-efficient probabilistic structure that tests whether an element 
 * is a member of a set. False positives are possible, but false negatives are not.
 * 
 * Time Complexity: O(k) where k is number of hash functions
 * Space Complexity: O(m) where m is bit array size
 * 
 * Real World Use Cases:
 * - Google BigTable (database)
 * - Bitcoin wallet synchronization
 * - Medium.com (recommendation system)
 * - Spell checkers
 * - Network routers
 * - Content recommendation systems
 */

class BloomFilter {
    /**
     * @param {number} size - Size of the bit array
     * @param {number} numHashes - Number of hash functions to use
     */
    constructor(size = 100, numHashes = 3) {
        this.size = size;
        this.numHashes = numHashes;
        this.bitArray = new Array(size).fill(false);
    }

    /**
     * Simple hash functions using different seeds
     * @param {string} item - Item to hash
     * @param {number} seed - Seed for hash variation
     * @returns {number} Hash value
     */
    _hash(item, seed) {
        let hash = 0;
        for (let i = 0; i < item.length; i++) {
            hash = (hash * seed + item.charCodeAt(i)) % this.size;
        }
        return hash;
    }

    /**
     * Get all hash values for an item
     * @param {string} item - Item to hash
     * @returns {number[]} Array of hash positions
     */
    _getHashes(item) {
        const hashes = [];
        // Using different prime numbers as seeds for variety
        const seeds = [17, 31, 43, 67, 89].slice(0, this.numHashes);
        
        for (const seed of seeds) {
            const hash = this._hash(item, seed);
            hashes.push(Math.abs(hash) % this.size);
        }
        return hashes;
    }

    /**
     * Add an item to the Bloom Filter
     * @param {string} item - Item to add
     */
    add(item) {
        const hashes = this._getHashes(item);
        for (const position of hashes) {
            this.bitArray[position] = true;
        }
    }

    /**
     * Check if an item MIGHT be in the set
     * @param {string} item - Item to check
     * @returns {boolean} True if probably exists (may have false positives)
     */
    mightContain(item) {
        const hashes = this._getHashes(item);
        for (const position of hashes) {
            if (!this.bitArray[position]) {
                return false; // Definitely not in set
            }
        }
        return true; // Probably in set (could be false positive)
    }

    /**
     * Calculate current approximate false positive rate
     * @returns {number} Estimated false positive probability
     */
    falsePositiveRate() {
        // Count how many bits are set to true
        const setBits = this.bitArray.filter(bit => bit).length;
        const ratio = setBits / this.size;
        
        // Formula: (1 - e^(-k * n / m)) ^ k
        return Math.pow(1 - Math.exp(-this.numHashes * ratio), this.numHashes);
    }

    /**
     * Get statistics about the Bloom Filter
     * @returns {Object} Statistics object
     */
    getStats() {
        const setBits = this.bitArray.filter(bit => bit).length;
        return {
            size: this.size,
            numHashes: this.numHashes,
            bitsSet: setBits,
            utilization: (setBits / this.size * 100).toFixed(2) + '%',
            falsePositiveRate: (this.falsePositiveRate() * 100).toFixed(2) + '%'
        };
    }

    /**
     * Clear the Bloom Filter
     */
    clear() {
        this.bitArray.fill(false);
    }
}

// Advanced Bloom Filter with better hash functions
class AdvancedBloomFilter extends BloomFilter {
    /**
     * Better hash function using MurmurHash inspiration
     */
    _hash(item, seed) {
        let hash = 0;
        for (let i = 0; i < item.length; i++) {
            hash = hash * seed + item.charCodeAt(i);
            hash = hash & hash; // Convert to 32-bit integer
        }
        return Math.abs(hash) % this.size;
    }
}

// Comprehensive test cases and examples
function testBloomFilter() {
    console.log("=== Bloom Filter Implementation ===\n");

    // Create a Bloom Filter
    const bloom = new BloomFilter(100, 3);
    
    // Test data
    const websites = [
        "google.com", "github.com", "stackoverflow.com", 
        "wikipedia.org", "youtube.com", "reddit.com"
    ];

    const notAdded = [
        "twitter.com", "facebook.com", "instagram.com",
        "amazon.com", "netflix.com"
    ];

    console.log("📝 Adding websites to Bloom Filter:");
    websites.forEach(site => {
        bloom.add(site);
        console.log(`   Added: ${site}`);
    });

    console.log("\n✅ Checking added websites (should all be true):");
    websites.forEach(site => {
        const result = bloom.mightContain(site);
        console.log(`   ${site}: ${result} ${result ? '✓' : '✗'}`);
    });

    console.log("\n❌ Checking non-added websites (might have false positives):");
    notAdded.forEach(site => {
        const result = bloom.mightContain(site);
        console.log(`   ${site}: ${result} ${!result ? '✓' : '?'}`);
    });

    console.log("\n📊 Bloom Filter Statistics:");
    console.log(bloom.getStats());

    // Demonstrate false positive concept
    console.log("\n🎯 Educational Example - False Positives:");
    const smallBloom = new BloomFilter(10, 2);
    smallBloom.add("test");
    console.log("   Small filter with 'test' added:");
    console.log("   Checking 'random':", smallBloom.mightContain("random"));
    console.log("   False positive rate:", (smallBloom.falsePositiveRate() * 100).toFixed(2) + '%');
}

// Real-world use case example
function spellCheckerExample() {
    console.log("\n=== Real World Example: Spell Checker ===");
    
    const dictionary = new BloomFilter(500, 4);
    const validWords = ["hello", "world", "javascript", "algorithm", "data", "structure"];
    
    validWords.forEach(word => dictionary.add(word));
    
    const testWords = ["hello", "helo", "world", "wordl", "algorithm", "algorith"];
    
    testWords.forEach(word => {
        const exists = dictionary.mightContain(word);
        console.log(`   "${word}" ${exists ? 'might be' : 'is definitely not'} in dictionary`);
    });
}

// Run tests
if (require.main === module) {
    testBloomFilter();
    spellCheckerExample();
}

module.exports = { BloomFilter, AdvancedBloomFilter };