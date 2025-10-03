/**
 * @file Trie.cpp
 * @brief Implementation of Trie (Prefix Tree) data structure
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Implement a trie with insert, search, and startsWith methods.
 *
 * Operations:
 * - insert(word): Inserts a word into the trie
 * - search(word): Returns true if the word is in the trie
 * - startsWith(prefix): Returns true if there is any word with the given prefix
 *
 * Algorithm: Tree-based structure where each node represents a character
 * - Each node contains array/map of child nodes (26 for lowercase a-z)
 * - Boolean flag marks end of valid word
 * - Traverse/create nodes character by character
 *
 * Time Complexity: O(m) for all operations, where m is the word/prefix length
 * Space Complexity: O(ALPHABET_SIZE * N * M) where N is number of words, M is average length
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Trie Node structure
 */
class TrieNode {
public:
    TrieNode* children[26];  // Array for 'a' to 'z'
    bool isEndOfWord;        // Flag to mark end of a word

    /**
     * @brief Constructor initializes node
     */
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

/**
 * @brief Trie (Prefix Tree) implementation
 */
class Trie {
private:
    TrieNode* root;

public:
    /**
     * @brief Constructor initializes trie with root node
     */
    Trie() {
        root = new TrieNode();
    }

    /**
     * @brief Insert a word into the trie
     * @param word Word to be inserted
     *
     * Algorithm:
     * 1. Start from root
     * 2. For each character, check if child node exists
     * 3. If not, create new node
     * 4. Move to child node
     * 5. Mark last node as end of word
     */
    void insert(string word) {
        TrieNode* current = root;

        // Traverse through each character
        for (char ch : word) {
            int index = ch - 'a';  // Convert char to index (0-25)

            // Create new node if path doesn't exist
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            // Move to child node
            current = current->children[index];
        }

        // Mark end of word
        current->isEndOfWord = true;
    }

    /**
     * @brief Search for a word in the trie
     * @param word Word to search for
     * @return true if word exists in trie, false otherwise
     *
     * Algorithm:
     * 1. Start from root
     * 2. For each character, check if child exists
     * 3. If any child doesn't exist, return false
     * 4. After traversing all characters, check isEndOfWord flag
     */
    bool search(string word) {
        TrieNode* current = root;

        // Traverse through each character
        for (char ch : word) {
            int index = ch - 'a';

            // If path doesn't exist, word is not in trie
            if (current->children[index] == nullptr) {
                return false;
            }

            // Move to child node
            current = current->children[index];
        }

        // Word exists only if we reach a node marked as end of word
        return current->isEndOfWord;
    }

    /**
     * @brief Check if there is any word in trie that starts with given prefix
     * @param prefix Prefix to search for
     * @return true if prefix exists in trie, false otherwise
     *
     * Algorithm:
     * 1. Start from root
     * 2. For each character in prefix, check if child exists
     * 3. If any child doesn't exist, return false
     * 4. If all characters found, return true (don't check isEndOfWord)
     */
    bool startsWith(string prefix) {
        TrieNode* current = root;

        // Traverse through each character
        for (char ch : prefix) {
            int index = ch - 'a';

            // If path doesn't exist, prefix is not in trie
            if (current->children[index] == nullptr) {
                return false;
            }

            // Move to child node
            current = current->children[index];
        }

        // Prefix exists (don't need to check isEndOfWord)
        return true;
    }

    /**
     * @brief Delete a word from the trie
     * @param word Word to be deleted
     * @return true if word was deleted, false if word didn't exist
     */
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }

    /**
     * @brief Helper function to recursively delete a word
     * @param current Current node being processed
     * @param word Word to delete
     * @param index Current character index
     * @return true if current node should be deleted
     */
    bool deleteHelper(TrieNode* current, string& word, int index) {
        if (index == word.length()) {
            // Base case: reached end of word
            if (!current->isEndOfWord) {
                return false;  // Word doesn't exist
            }

            current->isEndOfWord = false;  // Unmark end of word

            // Delete node if it has no children
            return isEmpty(current);
        }

        int charIndex = word[index] - 'a';
        TrieNode* child = current->children[charIndex];

        if (child == nullptr) {
            return false;  // Word doesn't exist
        }

        bool shouldDeleteChild = deleteHelper(child, word, index + 1);

        if (shouldDeleteChild) {
            delete child;
            current->children[charIndex] = nullptr;

            // Delete current node if it's not end of another word and has no children
            return !current->isEndOfWord && isEmpty(current);
        }

        return false;
    }

    /**
     * @brief Check if node has no children
     * @param node Node to check
     * @return true if node has no children
     */
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Get all words with given prefix
     * @param prefix Prefix to search for
     * @return Vector of all words with the prefix
     */
    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> results;
        TrieNode* current = root;

        // Navigate to prefix node
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return results;  // Prefix doesn't exist
            }
            current = current->children[index];
        }

        // Find all words from this node
        findAllWords(current, prefix, results);
        return results;
    }

    /**
     * @brief Helper function to find all words starting from a node
     * @param node Current node
     * @param currentWord Current word being formed
     * @param results Vector to store results
     */
    void findAllWords(TrieNode* node, string currentWord, vector<string>& results) {
        if (node->isEndOfWord) {
            results.push_back(currentWord);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char ch = 'a' + i;
                findAllWords(node->children[i], currentWord + ch, results);
            }
        }
    }

    /**
     * @brief Destructor to free memory
     */
    ~Trie() {
        destroyTrie(root);
    }

    /**
     * @brief Helper function to recursively destroy trie
     * @param node Current node to destroy
     */
    void destroyTrie(TrieNode* node) {
        if (node == nullptr) return;

        for (int i = 0; i < 26; i++) {
            destroyTrie(node->children[i]);
        }
        delete node;
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    Trie trie;

    cout << "=== Trie Operations ===" << endl << endl;

    // Insert words
    cout << "Inserting words: apple, app, application, apply, banana, band" << endl;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("banana");
    trie.insert("band");

    // Search operations
    cout << "\n--- Search Operations ---" << endl;
    cout << "search('apple'): " << (trie.search("apple") ? "true" : "false") << endl;
    cout << "search('app'): " << (trie.search("app") ? "true" : "false") << endl;
    cout << "search('appl'): " << (trie.search("appl") ? "true" : "false") << endl;
    cout << "search('orange'): " << (trie.search("orange") ? "true" : "false") << endl;

    // Prefix operations
    cout << "\n--- Prefix Operations ---" << endl;
    cout << "startsWith('app'): " << (trie.startsWith("app") ? "true" : "false") << endl;
    cout << "startsWith('ban'): " << (trie.startsWith("ban") ? "true" : "false") << endl;
    cout << "startsWith('cat'): " << (trie.startsWith("cat") ? "true" : "false") << endl;

    // Get all words with prefix
    cout << "\n--- Get Words with Prefix ---" << endl;
    vector<string> applyWords = trie.getWordsWithPrefix("app");
    cout << "Words starting with 'app': ";
    for (const string& word : applyWords) {
        cout << word << " ";
    }
    cout << endl;

    vector<string> banWords = trie.getWordsWithPrefix("ban");
    cout << "Words starting with 'ban': ";
    for (const string& word : banWords) {
        cout << word << " ";
    }
    cout << endl;

    // Delete operation
    cout << "\n--- Delete Operations ---" << endl;
    cout << "Deleting 'apple'" << endl;
    trie.deleteWord("apple");
    cout << "search('apple') after delete: " << (trie.search("apple") ? "true" : "false") << endl;
    cout << "search('app') after delete: " << (trie.search("app") ? "true" : "false") << endl;

    return 0;
}
