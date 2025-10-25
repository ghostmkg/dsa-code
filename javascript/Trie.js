/**
 * Trie (Prefix Tree) Implementation in JavaScript
 * 
 * A Trie is a tree-like data structure that stores strings in a way that
 * allows for efficient prefix-based searching, autocomplete, and spell checking.
 * 
 * Time Complexity:
 * - Insert: O(m) where m is the length of the word
 * - Search: O(m) where m is the length of the word
 * - Prefix Search: O(m) where m is the length of the prefix
 * 
 * Space Complexity: O(n * m) where n is number of words and m is average length
 */

class TrieNode {
    constructor() {
        this.children = new Map(); // Stores character -> TrieNode mappings
        this.isEndOfWord = false;  // Marks if this node completes a word
        this.frequency = 0;        // Optional: track how many times word was inserted
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
        this.totalWords = 0;
    }

    /**
     * Insert a word into the trie
     * @param {string} word - The word to insert
     */
    insert(word) {
        if (!word || word.length === 0) return false;

        let currentNode = this.root;
        
        for (let char of word.toLowerCase()) {
            if (!currentNode.children.has(char)) {
                currentNode.children.set(char, new TrieNode());
            }
            currentNode = currentNode.children.get(char);
        }
        
        // Mark the end of word and update frequency
        if (!currentNode.isEndOfWord) {
            this.totalWords++;
        }
        currentNode.isEndOfWord = true;
        currentNode.frequency++;
        
        return true;
    }

    /**
     * Search for a complete word in the trie
     * @param {string} word - The word to search for
     * @returns {boolean} - True if word exists
     */
    search(word) {
        if (!word || word.length === 0) return false;

        let currentNode = this.root;
        
        for (let char of word.toLowerCase()) {
            if (!currentNode.children.has(char)) {
                return false;
            }
            currentNode = currentNode.children.get(char);
        }
        
        return currentNode.isEndOfWord;
    }

    /**
     * Check if any word in trie starts with given prefix
     * @param {string} prefix - The prefix to check
     * @returns {boolean} - True if prefix exists
     */
    startsWith(prefix) {
        if (!prefix || prefix.length === 0) return false;

        let currentNode = this.root;
        
        for (let char of prefix.toLowerCase()) {
            if (!currentNode.children.has(char)) {
                return false;
            }
            currentNode = currentNode.children.get(char);
        }
        
        return true;
    }

    /**
     * Get all words with given prefix (autocomplete)
     * @param {string} prefix - The prefix to autocomplete
     * @returns {string[]} - Array of matching words
     */
    autocomplete(prefix) {
        if (!prefix || prefix.length === 0) return [];
        
        let currentNode = this.root;
        const results = [];
        
        // Navigate to the prefix node
        for (let char of prefix.toLowerCase()) {
            if (!currentNode.children.has(char)) {
                return results; // No words with this prefix
            }
            currentNode = currentNode.children.get(char);
        }
        
        // Collect all words from this node
        this._collectWords(currentNode, prefix, results);
        return results;
    }

    /**
     * Helper method to collect all words from a node
     * @param {TrieNode} node - Current node
     * @param {string} currentWord - Current word being built
     * @param {string[]} results - Array to store results
     */
    _collectWords(node, currentWord, results) {
        if (node.isEndOfWord) {
            results.push({
                word: currentWord,
                frequency: node.frequency
            });
        }
        
        for (let [char, childNode] of node.children) {
            this._collectWords(childNode, currentWord + char, results);
        }
    }

    /**
     * Delete a word from the trie
     * @param {string} word - The word to delete
     * @returns {boolean} - True if word was deleted
     */
    delete(word) {
        if (!word || word.length === 0) return false;
        return this._deleteHelper(this.root, word.toLowerCase(), 0);
    }

    /**
     * Recursive helper for deletion
     */
    _deleteHelper(node, word, index) {
        if (index === word.length) {
            if (!node.isEndOfWord) return false;
            
            node.isEndOfWord = false;
            this.totalWords--;
            return node.children.size === 0; // Can be deleted if no children
        }
        
        const char = word[index];
        if (!node.children.has(char)) return false;
        
        const childNode = node.children.get(char);
        const shouldDeleteChild = this._deleteHelper(childNode, word, index + 1);
        
        if (shouldDeleteChild) {
            node.children.delete(char);
            return node.children.size === 0 && !node.isEndOfWord;
        }
        
        return false;
    }

    /**
     * Get the longest common prefix of all words
     * @returns {string} - Longest common prefix
     */
    longestCommonPrefix() {
        let prefix = "";
        let currentNode = this.root;
        
        while (currentNode.children.size === 1 && !currentNode.isEndOfWord) {
            const [char, childNode] = Array.from(currentNode.children)[0];
            prefix += char;
            currentNode = childNode;
        }
        
        return prefix;
    }

    /**
     * Get total number of words in trie
     * @returns {number} - Word count
     */
    getWordCount() {
        return this.totalWords;
    }

    /**
     * Get all words in trie
     * @returns {string[]} - All words
     */
    getAllWords() {
        const results = [];
        this._collectWords(this.root, "", results);
        return results.map(item => item.word).sort();
    }

    /**
     * Clear the entire trie
     */
    clear() {
        this.root = new TrieNode();
        this.totalWords = 0;
    }
}

// Example Usage and Test Cases
function demonstrateTrie() {
    console.log("=== Trie Data Structure Demonstration ===\n");
    
    const trie = new Trie();
    
    // Insert words
    const words = ["apple", "app", "application", "banana", "bat", "ball", "cat"];
    words.forEach(word => trie.insert(word));
    
    console.log("1. Inserted words:", words);
    console.log("Total words in trie:", trie.getWordCount());
    
    // Search operations
    console.log("\n2. Search Operations:");
    console.log("Search 'apple':", trie.search("apple"));     // true
    console.log("Search 'app':", trie.search("app"));         // true  
    console.log("Search 'appl':", trie.search("appl"));       // false
    console.log("Search 'dog':", trie.search("dog"));         // false
    
    // Prefix search
    console.log("\n3. Prefix Search:");
    console.log("StartsWith 'app':", trie.startsWith("app")); // true
    console.log("StartsWith 'ba':", trie.startsWith("ba"));   // true
    console.log("StartsWith 'dog':", trie.startsWith("dog")); // false
    
    // Autocomplete
    console.log("\n4. Autocomplete Suggestions:");
    console.log("Prefix 'app':", trie.autocomplete("app").map(item => item.word));
    console.log("Prefix 'ba':", trie.autocomplete("ba").map(item => item.word));
    console.log("Prefix 'c':", trie.autocomplete("c").map(item => item.word));
    
    // Delete operations
    console.log("\n5. Delete Operations:");
    console.log("Delete 'app':", trie.delete("app"));
    console.log("Search 'app' after deletion:", trie.search("app")); // false
    console.log("StartsWith 'app' after deletion:", trie.startsWith("app")); // true
    console.log("Autocomplete 'app' after deletion:", trie.autocomplete("app").map(item => item.word));
    
    // Longest common prefix
    console.log("\n6. Longest Common Prefix:", trie.longestCommonPrefix());
    
    // Get all words
    console.log("\n7. All words in trie:", trie.getAllWords());
}

// Advanced Example: Spell Checker using Trie
class SpellChecker {
    constructor() {
        this.trie = new Trie();
    }
    
    addToDictionary(words) {
        words.forEach(word => this.trie.insert(word));
    }
    
    suggestCorrections(word, maxSuggestions = 5) {
        if (this.trie.search(word)) {
            return [`"${word}" is spelled correctly!`];
        }
        
        const suggestions = this.trie.autocomplete(word.slice(0, 3));
        return suggestions
            .sort((a, b) => b.frequency - a.frequency)
            .slice(0, maxSuggestions)
            .map(item => item.word);
    }
}

// Demonstrate spell checker
function demonstrateSpellChecker() {
    console.log("\n\n=== Spell Checker Demonstration ===");
    
    const spellChecker = new SpellChecker();
    const dictionary = [
        "hello", "world", "javascript", "programming", 
        "algorithm", "data", "structure", "computer",
        "science", "code", "development", "web"
    ];
    
    spellChecker.addToDictionary(dictionary);
    
    console.log("Suggestions for 'prog':", spellChecker.suggestCorrections("prog"));
    console.log("Suggestions for 'dat':", spellChecker.suggestCorrections("dat"));
    console.log("Suggestions for 'xyz':", spellChecker.suggestCorrections("xyz"));
}

// Run demonstrations
if (require.main === module) {
    demonstrateTrie();
    demonstrateSpellChecker();
}

module.exports = { Trie, TrieNode, SpellChecker };