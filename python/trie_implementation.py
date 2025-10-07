"""
Trie (Prefix Tree) Implementation in Python

A Trie is a tree-like data structure that stores strings in a way that makes 
searching for prefixes very efficient. It's commonly used for:
- Autocomplete functionality
- Spell checkers
- IP routing (longest prefix matching)
- Word games

Time Complexity:
- Insert: O(m) where m is the length of the string
- Search: O(m) where m is the length of the string
- Delete: O(m) where m is the length of the string
- Prefix Search: O(m) where m is the length of the prefix

Space Complexity: O(ALPHABET_SIZE * N * M) where N is the number of strings 
and M is the average length of the strings.
"""

class TrieNode:
    """Node class for Trie data structure"""
    
    def __init__(self):
        self.children = {}  # Dictionary to store child nodes
        self.is_end_of_word = False  # Flag to mark end of word
        self.word_count = 0  # Count of words that end at this node


class Trie:
    """Trie (Prefix Tree) implementation"""
    
    def __init__(self):
        self.root = TrieNode()
        self.total_words = 0
    
    def insert(self, word):
        """
        Insert a word into the trie
        
        Args:
            word (str): The word to insert
        """
        if not word:
            return
        
        current = self.root
        
        for char in word:
            if char not in current.children:
                current.children[char] = TrieNode()
            current = current.children[char]
            current.word_count += 1
        
        if not current.is_end_of_word:
            current.is_end_of_word = True
            self.total_words += 1
    
    def search(self, word):
        """
        Search for a word in the trie
        
        Args:
            word (str): The word to search for
            
        Returns:
            bool: True if word exists, False otherwise
        """
        if not word:
            return False
        
        current = self.root
        
        for char in word:
            if char not in current.children:
                return False
            current = current.children[char]
        
        return current.is_end_of_word
    
    def starts_with(self, prefix):
        """
        Check if any word in the trie starts with the given prefix
        
        Args:
            prefix (str): The prefix to search for
            
        Returns:
            bool: True if prefix exists, False otherwise
        """
        if not prefix:
            return True
        
        current = self.root
        
        for char in prefix:
            if char not in current.children:
                return False
            current = current.children[char]
        
        return True
    
    def delete(self, word):
        """
        Delete a word from the trie
        
        Args:
            word (str): The word to delete
            
        Returns:
            bool: True if word was deleted, False if word doesn't exist
        """
        if not word or not self.search(word):
            return False
        
        current = self.root
        
        # Navigate to the end of the word
        for char in word:
            current.children[char].word_count -= 1
            current = current.children[char]
        
        # Mark as not end of word
        current.is_end_of_word = False
        self.total_words -= 1
        
        # Clean up unused nodes (optional optimization)
        self._cleanup_nodes(word)
        
        return True
    
    def _cleanup_nodes(self, word):
        """
        Helper method to remove unused nodes after deletion
        
        Args:
            word (str): The word that was deleted
        """
        current = self.root
        path = []
        
        for char in word:
            path.append((current, char))
            current = current.children[char]
        
        # Remove nodes from the end if they have no children and are not end of word
        for node, char in reversed(path):
            if (not node.children[char].children and 
                not node.children[char].is_end_of_word and
                node.children[char].word_count == 0):
                del node.children[char]
            else:
                break
    
    def get_all_words_with_prefix(self, prefix):
        """
        Get all words that start with the given prefix
        
        Args:
            prefix (str): The prefix to search for
            
        Returns:
            list: List of words that start with the prefix
        """
        if not self.starts_with(prefix):
            return []
        
        current = self.root
        
        # Navigate to the prefix node
        for char in prefix:
            current = current.children[char]
        
        words = []
        self._collect_words(current, prefix, words)
        return words
    
    def _collect_words(self, node, current_word, words):
        """
        Helper method to collect all words from a given node
        
        Args:
            node (TrieNode): Current node
            current_word (str): Current word being built
            words (list): List to store found words
        """
        if node.is_end_of_word:
            words.append(current_word)
        
        for char, child_node in node.children.items():
            self._collect_words(child_node, current_word + char, words)
    
    def get_word_count(self):
        """
        Get the total number of words in the trie
        
        Returns:
            int: Total number of words
        """
        return self.total_words
    
    def is_empty(self):
        """
        Check if the trie is empty
        
        Returns:
            bool: True if trie is empty, False otherwise
        """
        return self.total_words == 0
    
    def clear(self):
        """Clear all words from the trie"""
        self.root = TrieNode()
        self.total_words = 0


def demo_trie_operations():
    """Demonstrate various trie operations"""
    print("=== Trie Implementation Demo ===\n")
    
    # Create a new trie
    trie = Trie()
    
    # Insert words
    words = ["apple", "app", "application", "apply", "banana", "band", "bandana"]
    print("Inserting words:", words)
    for word in words:
        trie.insert(word)
    
    print(f"Total words in trie: {trie.get_word_count()}\n")
    
    # Search for words
    search_words = ["app", "apple", "application", "banana", "orange"]
    print("Searching for words:")
    for word in search_words:
        result = trie.search(word)
        print(f"  '{word}': {'Found' if result else 'Not found'}")
    
    print()
    
    # Check prefixes
    prefixes = ["app", "ban", "ora", "ap"]
    print("Checking prefixes:")
    for prefix in prefixes:
        result = trie.starts_with(prefix)
        print(f"  Words starting with '{prefix}': {'Yes' if result else 'No'}")
    
    print()
    
    # Get all words with specific prefix
    prefix = "app"
    words_with_prefix = trie.get_all_words_with_prefix(prefix)
    print(f"All words starting with '{prefix}': {words_with_prefix}")
    
    print()
    
    # Delete a word
    word_to_delete = "app"
    print(f"Deleting word: '{word_to_delete}'")
    deleted = trie.delete(word_to_delete)
    print(f"Deletion {'successful' if deleted else 'failed'}")
    print(f"Total words after deletion: {trie.get_word_count()}")
    
    # Check if word still exists
    print(f"'{word_to_delete}' still exists: {'Yes' if trie.search(word_to_delete) else 'No'}")
    
    print()
    
    # Get all words with prefix after deletion
    words_with_prefix = trie.get_all_words_with_prefix("app")
    print(f"All words starting with 'app' after deletion: {words_with_prefix}")


if __name__ == "__main__":
    demo_trie_operations()
