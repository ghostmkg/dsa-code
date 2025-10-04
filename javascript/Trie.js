/**
 * Trie (Prefix Tree) Data Structure
 * 
 * Description: Tree-like data structure for efficient string storage and retrieval.
 * Each node represents a character, enabling fast prefix-based operations.
 * 
 * Time Complexity: 
 * - Insert: O(m) where m is word length
 * - Search: O(m)
 * - StartsWith: O(m)
 * - Delete: O(m)
 * 
 * Space Complexity: O(ALPHABET_SIZE × N × M) where N is number of words
 * 
 * Use Cases:
 * - Autocomplete and search suggestions
 * - Spell checkers
 * - IP routing tables
 * - Dictionary implementations
 * 
 * Example:
 * trie.insert("apple");
 * trie.search("apple");   // true
 * trie.startsWith("app"); // true
 */

class TrieNode {
    constructor() {
        this.children = new Map();
        this.isEndOfWord = false;
        this.wordCount = 0; // For counting word frequency
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
        this.size = 0;
    }

    /**
     * Insert a word into the trie
     * @param {string} word - Word to insert
     */
    insert(word) {
        if (typeof word !== 'string') {
            throw new Error('Input must be a string');
        }

        let node = this.root;
        
        for (let char of word) {
            if (!node.children.has(char)) {
                node.children.set(char, new TrieNode());
            }
            node = node.children.get(char);
        }

        if (!node.isEndOfWord) {
            this.size++;
        }
        node.isEndOfWord = true;
        node.wordCount++;
    }

    /**
     * Search for exact word match
     * @param {string} word - Word to search
     * @returns {boolean}
     */
    search(word) {
        const node = this._findNode(word);
        return node !== null && node.isEndOfWord;
    }

    /**
     * Check if any word starts with given prefix
     * @param {string} prefix - Prefix to search
     * @returns {boolean}
     */
    startsWith(prefix) {
        return this._findNode(prefix) !== null;
    }

    /**
     * Find node at end of given string
     * @private
     */
    _findNode(str) {
        let node = this.root;
        
        for (let char of str) {
            if (!node.children.has(char)) {
                return null;
            }
            node = node.children.get(char);
        }
        
        return node;
    }

    /**
     * Delete a word from the trie
     * @param {string} word - Word to delete
     * @returns {boolean} - True if deleted
     */
    delete(word) {
        const deleteHelper = (node, word, index) => {
            if (index === word.length) {
                if (!node.isEndOfWord) return false;
                
                node.isEndOfWord = false;
                node.wordCount = 0;
                this.size--;
                
                return node.children.size === 0;
            }

            const char = word[index];
            const childNode = node.children.get(char);
            
            if (!childNode) return false;

            const shouldDeleteChild = deleteHelper(childNode, word, index + 1);

            if (shouldDeleteChild) {
                node.children.delete(char);
                return node.children.size === 0 && !node.isEndOfWord;
            }

            return false;
        };

        return deleteHelper(this.root, word, 0);
    }

    /**
     * Get all words with given prefix
     * @param {string} prefix - Prefix to search
     * @returns {string[]} - Array of matching words
     */
    getAllWordsWithPrefix(prefix) {
        const results = [];
        const node = this._findNode(prefix);
        
        if (!node) return results;

        const dfs = (node, currentWord) => {
            if (node.isEndOfWord) {
                results.push(currentWord);
            }

            for (let [char, childNode] of node.children) {
                dfs(childNode, currentWord + char);
            }
        };

        dfs(node, prefix);
        return results;
    }

    /**
     * Get all words in the trie
     * @returns {string[]}
     */
    getAllWords() {
        return this.getAllWordsWithPrefix('');
    }

    /**
     * Count words with given prefix
     * @param {string} prefix
     * @returns {number}
     */
    countWordsWithPrefix(prefix) {
        return this.getAllWordsWithPrefix(prefix).length;
    }

    /**
     * Find longest common prefix
     * @returns {string}
     */
    longestCommonPrefix() {
        let prefix = '';
        let node = this.root;

        while (node.children.size === 1 && !node.isEndOfWord) {
            const [char, childNode] = Array.from(node.children)[0];
            prefix += char;
            node = childNode;
        }

        return prefix;
    }

    /**
     * Autocomplete suggestions
     * @param {string} prefix - Partial word
     * @param {number} limit - Max suggestions
     * @returns {string[]}
     */
    autocomplete(prefix, limit = 10) {
        const words = this.getAllWordsWithPrefix(prefix);
        return words.slice(0, limit);
    }

    /**
     * Check if trie is empty
     * @returns {boolean}
     */
    isEmpty() {
        return this.size === 0;
    }

    /**
     * Get number of words in trie
     * @returns {number}
     */
    getSize() {
        return this.size;
    }

    /**
     * Clear all words from trie
     */
    clear() {
        this.root = new TrieNode();
        this.size = 0;
    }

    /**
     * Get word frequency
     * @param {string} word
     * @returns {number}
     */
    getWordFrequency(word) {
        const node = this._findNode(word);
        return node && node.isEndOfWord ? node.wordCount : 0;
    }

    /**
     * Find shortest unique prefix for each word
     * @returns {Map<string, string>}
     */
    getShortestUniquePrefixes() {
        const prefixes = new Map();
        const words = this.getAllWords();

        for (let word of words) {
            let prefix = '';
            let node = this.root;

            for (let char of word) {
                prefix += char;
                node = node.children.get(char);

                if (node.children.size === 1 || node.isEndOfWord) {
                    break;
                }
            }

            prefixes.set(word, prefix);
        }

        return prefixes;
    }

    /**
     * Pattern matching with wildcards (. matches any character)
     * @param {string} pattern
     * @returns {string[]}
     */
    searchWithWildcard(pattern) {
        const results = [];

        const dfs = (node, index, currentWord) => {
            if (index === pattern.length) {
                if (node.isEndOfWord) {
                    results.push(currentWord);
                }
                return;
            }

            const char = pattern[index];

            if (char === '.') {
                for (let [c, childNode] of node.children) {
                    dfs(childNode, index + 1, currentWord + c);
                }
            } else {
                if (node.children.has(char)) {
                    dfs(node.children.get(char), index + 1, currentWord + char);
                }
            }
        };

        dfs(this.root, 0, '');
        return results;
    }

    /**
     * Visualize trie structure
     */
    visualize() {
        const visualizeHelper = (node, prefix, isLast, lines) => {
            const children = Array.from(node.children.entries());
            
            for (let i = 0; i < children.length; i++) {
                const [char, childNode] = children[i];
                const isLastChild = i === children.length - 1;
                const marker = childNode.isEndOfWord ? `[${char}]` : char;
                
                lines.push(prefix + (isLastChild ? '└── ' : '├── ') + marker);
                
                visualizeHelper(
                    childNode,
                    prefix + (isLastChild ? '    ' : '│   '),
                    isLastChild,
                    lines
                );
            }
        };

        const lines = ['Root'];
        visualizeHelper(this.root, '', true, lines);
        return lines.join('\n');
    }
}

// Test cases
const trie = new Trie();

// Insert words
const words = ['apple', 'app', 'application', 'apply', 'banana', 'band', 'bandana'];
words.forEach(word => trie.insert(word));

console.log('Trie size:', trie.getSize()); // 7

console.log('\nSearch tests:');
console.log('search("apple"):', trie.search('apple')); // true
console.log('search("app"):', trie.search('app')); // true
console.log('search("appl"):', trie.search('appl')); // false

console.log('\nPrefix tests:');
console.log('startsWith("app"):', trie.startsWith('app')); // true
console.log('startsWith("ban"):', trie.startsWith('ban')); // true

console.log('\nWords with prefix "app":');
console.log(trie.getAllWordsWithPrefix('app')); // ['app', 'apple', 'application', 'apply']

console.log('\nAutocomplete "ban":');
console.log(trie.autocomplete('ban', 5)); // ['banana', 'band', 'bandana']

console.log('\nLongest common prefix:', trie.longestCommonPrefix());

console.log('\nWildcard search "app..":');
console.log(trie.searchWithWildcard('app..')); // ['apple', 'apply']

console.log('\nTrie visualization:');
console.log(trie.visualize());

console.log('\nDelete "app":', trie.delete('app')); // true
console.log('After deletion, search("app"):', trie.search('app')); // false
console.log('Size after deletion:', trie.getSize()); // 6

module.exports = Trie;
