class Trie {
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode temp = root;

        for (char c : word.toCharArray()) {
            temp.children.putIfAbsent(c, new TrieNode());
            temp = temp.children.get(c);
        }

        temp.isword = true;
    }

    public boolean search(String word) {
        TrieNode temp = root;

        for (char c : word.toCharArray()) {

            if (!temp.children.containsKey(c)) {
                return false;
            }

            temp = temp.children.get(c);
        }

        return temp.isword;

    }

    public boolean startsWith(String prefix) {
        TrieNode temp = root;

        for (char c : prefix.toCharArray()) {

            if (!temp.children.containsKey(c)) {
                return false;
            }

            temp = temp.children.get(c);
        }

        return true;
    }
}

class TrieNode {
    HashMap<Character, TrieNode> children = new HashMap<>();
    boolean isword = false;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */