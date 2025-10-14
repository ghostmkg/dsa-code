# ------------------------------------------------------------
# Data Structure: Trie (Prefix Tree)
# Difficulty: Medium
# Source: Standard Data Structure
# ------------------------------------------------------------
# Statement:
# Implement a Trie (Prefix Tree) with the following methods:
# - `insert(word)`: Inserts a word into the trie.
# - `search(word)`: Returns `True` if the word is in the trie.
# - `startsWith(prefix)`: Returns `True` if there is any word in the
#   trie that starts with the given prefix.
#
# A Trie is a tree-like data structure that stores a dynamic set of
# strings. It is commonly used for efficient retrieval of keys in a dataset
# of strings, such as autocomplete features or spell checkers.
#
# ------------------------------------------------------------

class TrieNode:
    """A node in the Trie structure."""
    def __init__(self):
        # `children` is a dictionary mapping a character to a TrieNode.
        self.children = {}
        # `is_end_of_word` is True if the node represents the end of a word.
        self.is_end_of_word = False

class Trie:
    """
    Trie (Prefix Tree) implementation.

    Approach:
    The Trie is built from a root node. Each node has a dictionary of children
    and a boolean flag to mark the end of a word.

    - `insert`: Traverse the trie character by character. If a character's
      node doesn't exist, create it. Mark the final node as the end of a word.
      Time Complexity: O(L), where L is the length of the word.
      Space Complexity: O(L) in the worst case (for a new word).

    - `search`: Traverse the trie. If any character is not found, the word
      doesn't exist. If the traversal completes, check if the final node
      is marked as the end of a word.
      Time Complexity: O(L).
      Space Complexity: O(1).

    - `startsWith`: Traverse the trie. If any character in the prefix is not
      found, no word starts with it. If traversal completes, the prefix exists.
      Time Complexity: O(P), where P is the length of the prefix.
      Space Complexity: O(1).
    """
    def __init__(self):
        """Initializes the trie structure."""
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """Inserts a word into the trie."""
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """Returns True if the word is in the trie."""
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        """Returns True if there is any word in the trie that starts with the given prefix."""
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

# ------------------------------------------------------------
# Driver Code for Testing
# ------------------------------------------------------------
if __name__ == "__main__":
    trie = Trie()

    # --- Insert words ---
    words_to_insert = ["apple", "app", "apricot", "banana", "bandana"]
    for word in words_to_insert:
        trie.insert(word)
    print(f"Inserted words: {words_to_insert}\n")

    # --- Test search() method ---
    print("--- Testing search() ---")
    print(f"Search 'apple': {trie.search('apple')}")        # Expected: True
    print(f"Search 'app': {trie.search('app')}")          # Expected: True
    print(f"Search 'appl': {trie.search('appl')}")         # Expected: False
    print(f"Search 'banana': {trie.search('banana')}")      # Expected: True
    print(f"Search 'ban': {trie.search('ban')}")          # Expected: False
    print(f"Search 'bandanas': {trie.search('bandanas')}")  # Expected: False
    print("-" * 20)

    # --- Test startsWith() method ---
    print("--- Testing startsWith() ---")
    print(f"Starts with 'app': {trie.startsWith('app')}")      # Expected: True
    print(f"Starts with 'apri': {trie.startsWith('apri')}")   # Expected: True
    print(f"Starts with 'ban': {trie.startsWith('ban')}")      # Expected: True
    print(f"Starts with 'bana': {trie.startsWith('bana')}")    # Expected: True
    print(f"Starts with 'band': {trie.startsWith('band')}")    # Expected: True
    print(f"Starts with 'cat': {trie.startsWith('cat')}")      # Expected: False
    print(f"Starts with 'applepie': {trie.startsWith('applepie')}") # Expected: False
    print("-" * 20)
