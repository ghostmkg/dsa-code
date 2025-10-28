/**
 * Binary Search Tree Implementation
 * A Binary Search Tree (BST) is a node-based binary tree data structure with the following properties:
 * - The left subtree of a node contains only nodes with keys less than the node's key
 * - The right subtree of a node contains only nodes with keys greater than the node's key
 * - Both left and right subtrees must also be binary search trees
 * 
 * Time Complexity:
 * - Insert: O(log n) average, O(n) worst case
 * - Search: O(log n) average, O(n) worst case
 * - Delete: O(log n) average, O(n) worst case
 * - Traversals: O(n)
 * 
 * Space Complexity: O(n)
 */

class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  /**
   * Insert a value into the BST
   * @param {number} value - The value to insert
   * @returns {BinarySearchTree} - Returns this for method chaining
   */
  insert(value) {
    const newNode = new Node(value);

    if (this.root === null) {
      this.root = newNode;
      return this;
    }

    let current = this.root;
    while (true) {
      if (value === current.value) return this; // Avoid duplicates
      
      if (value < current.value) {
        if (current.left === null) {
          current.left = newNode;
          return this;
        }
        current = current.left;
      } else {
        if (current.right === null) {
          current.right = newNode;
          return this;
        }
        current = current.right;
      }
    }
  }

  /**
   * Search for a value in the BST
   * @param {number} value - The value to search for
   * @returns {boolean} - True if found, false otherwise
   */
  search(value) {
    if (this.root === null) return false;

    let current = this.root;
    while (current !== null) {
      if (value === current.value) return true;
      if (value < current.value) {
        current = current.left;
      } else {
        current = current.right;
      }
    }
    return false;
  }

  /**
   * Find a node with a specific value
   * @param {number} value - The value to find
   * @returns {Node|null} - The node if found, null otherwise
   */
  find(value) {
    if (this.root === null) return null;

    let current = this.root;
    while (current !== null) {
      if (value === current.value) return current;
      if (value < current.value) {
        current = current.left;
      } else {
        current = current.right;
      }
    }
    return null;
  }

  /**
   * Delete a value from the BST
   * @param {number} value - The value to delete
   * @returns {BinarySearchTree} - Returns this for method chaining
   */
  delete(value) {
    this.root = this._deleteNode(this.root, value);
    return this;
  }

  /**
   * Helper method to delete a node recursively
   * @private
   */
  _deleteNode(node, value) {
    if (node === null) return null;

    if (value < node.value) {
      node.left = this._deleteNode(node.left, value);
      return node;
    } else if (value > node.value) {
      node.right = this._deleteNode(node.right, value);
      return node;
    } else {
      // Node to delete found
      
      // Case 1: Node has no children (leaf node)
      if (node.left === null && node.right === null) {
        return null;
      }

      // Case 2: Node has one child
      if (node.left === null) return node.right;
      if (node.right === null) return node.left;

      // Case 3: Node has two children
      // Find the minimum value in the right subtree (inorder successor)
      let minRight = this._findMin(node.right);
      node.value = minRight.value;
      node.right = this._deleteNode(node.right, minRight.value);
      return node;
    }
  }

  /**
   * Find the node with minimum value in a subtree
   * @private
   */
  _findMin(node) {
    while (node.left !== null) {
      node = node.left;
    }
    return node;
  }

  /**
   * Find the minimum value in the BST
   * @returns {number|null} - The minimum value or null if tree is empty
   */
  findMin() {
    if (this.root === null) return null;
    let current = this.root;
    while (current.left !== null) {
      current = current.left;
    }
    return current.value;
  }

  /**
   * Find the maximum value in the BST
   * @returns {number|null} - The maximum value or null if tree is empty
   */
  findMax() {
    if (this.root === null) return null;
    let current = this.root;
    while (current.right !== null) {
      current = current.right;
    }
    return current.value;
  }

  /**
   * In-order traversal (Left -> Root -> Right)
   * Results in sorted order for BST
   * @returns {number[]} - Array of values in sorted order
   */
  inOrderTraversal() {
    const result = [];
    this._inOrder(this.root, result);
    return result;
  }

  _inOrder(node, result) {
    if (node !== null) {
      this._inOrder(node.left, result);
      result.push(node.value);
      this._inOrder(node.right, result);
    }
  }

  /**
   * Pre-order traversal (Root -> Left -> Right)
   * @returns {number[]} - Array of values in pre-order
   */
  preOrderTraversal() {
    const result = [];
    this._preOrder(this.root, result);
    return result;
  }

  _preOrder(node, result) {
    if (node !== null) {
      result.push(node.value);
      this._preOrder(node.left, result);
      this._preOrder(node.right, result);
    }
  }

  /**
   * Post-order traversal (Left -> Right -> Root)
   * @returns {number[]} - Array of values in post-order
   */
  postOrderTraversal() {
    const result = [];
    this._postOrder(this.root, result);
    return result;
  }

  _postOrder(node, result) {
    if (node !== null) {
      this._postOrder(node.left, result);
      this._postOrder(node.right, result);
      result.push(node.value);
    }
  }

  /**
   * Level-order traversal (Breadth-First Search)
   * @returns {number[]} - Array of values in level order
   */
  levelOrderTraversal() {
    if (this.root === null) return [];

    const result = [];
    const queue = [this.root];

    while (queue.length > 0) {
      const node = queue.shift();
      result.push(node.value);

      if (node.left !== null) queue.push(node.left);
      if (node.right !== null) queue.push(node.right);
    }

    return result;
  }

  /**
   * Get the height of the tree
   * @returns {number} - The height of the tree (-1 for empty tree)
   */
  height() {
    return this._calculateHeight(this.root);
  }

  _calculateHeight(node) {
    if (node === null) return -1;
    return 1 + Math.max(this._calculateHeight(node.left), this._calculateHeight(node.right));
  }

  /**
   * Check if the tree is balanced
   * A tree is balanced if the heights of the two subtrees of any node differ by at most 1
   * @returns {boolean} - True if balanced, false otherwise
   */
  isBalanced() {
    return this._checkBalance(this.root) !== -1;
  }

  _checkBalance(node) {
    if (node === null) return 0;

    const leftHeight = this._checkBalance(node.left);
    if (leftHeight === -1) return -1;

    const rightHeight = this._checkBalance(node.right);
    if (rightHeight === -1) return -1;

    if (Math.abs(leftHeight - rightHeight) > 1) return -1;

    return Math.max(leftHeight, rightHeight) + 1;
  }

  /**
   * Count the total number of nodes in the tree
   * @returns {number} - The number of nodes
   */
  size() {
    return this._countNodes(this.root);
  }

  _countNodes(node) {
    if (node === null) return 0;
    return 1 + this._countNodes(node.left) + this._countNodes(node.right);
  }
}

// Example usage and test cases
const bst = new BinarySearchTree();

// Insert values
bst.insert(50);
bst.insert(30);
bst.insert(70);
bst.insert(20);
bst.insert(40);
bst.insert(60);
bst.insert(80);

console.log("In-order traversal (sorted):", bst.inOrderTraversal());
// Output: [20, 30, 40, 50, 60, 70, 80]

console.log("Pre-order traversal:", bst.preOrderTraversal());
// Output: [50, 30, 20, 40, 70, 60, 80]

console.log("Post-order traversal:", bst.postOrderTraversal());
// Output: [20, 40, 30, 60, 80, 70, 50]

console.log("Level-order traversal:", bst.levelOrderTraversal());
// Output: [50, 30, 70, 20, 40, 60, 80]

console.log("Search for 40:", bst.search(40)); // true
console.log("Search for 100:", bst.search(100)); // false

console.log("Minimum value:", bst.findMin()); // 20
console.log("Maximum value:", bst.findMax()); // 80

console.log("Tree height:", bst.height()); // 2
console.log("Tree size:", bst.size()); // 7
console.log("Is balanced:", bst.isBalanced()); // true

// Delete a node
bst.delete(30);
console.log("After deleting 30:", bst.inOrderTraversal());
// Output: [20, 40, 50, 60, 70, 80]

module.exports = { BinarySearchTree, Node };