/**
 * AVL Tree (Self-Balancing Binary Search Tree)
 * 
 * Description: Height-balanced BST where the difference between heights of left
 * and right subtrees cannot be more than 1 for all nodes. Named after inventors
 * Adelson-Velsky and Landis.
 * 
 * Time Complexity:
 * - Insert: O(log n)
 * - Delete: O(log n)
 * - Search: O(log n)
 * 
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - Databases and file systems
 * - Priority queues
 * - Associative arrays
 * - When frequent lookups with occasional updates
 * 
 * Example:
 * avl.insert(10);
 * avl.search(10);  // true
 * avl.delete(10);
 */

class AVLNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

class AVLTree {
    constructor() {
        this.root = null;
        this.size = 0;
    }

    /**
     * Get height of node
     * @private
     */
    _getHeight(node) {
        return node ? node.height : 0;
    }

    /**
     * Get balance factor of node
     * @private
     */
    _getBalance(node) {
        return node ? this._getHeight(node.left) - this._getHeight(node.right) : 0;
    }

    /**
     * Update height of node
     * @private
     */
    _updateHeight(node) {
        if (node) {
            node.height = 1 + Math.max(
                this._getHeight(node.left),
                this._getHeight(node.right)
            );
        }
    }

    /**
     * Right rotation
     * @private
     */
    _rotateRight(y) {
        const x = y.left;
        const T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Update heights
        this._updateHeight(y);
        this._updateHeight(x);

        return x;
    }

    /**
     * Left rotation
     * @private
     */
    _rotateLeft(x) {
        const y = x.right;
        const T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        // Update heights
        this._updateHeight(x);
        this._updateHeight(y);

        return y;
    }

    /**
     * Insert value into AVL tree
     * @param {number} value - Value to insert
     */
    insert(value) {
        this.root = this._insertNode(this.root, value);
        this.size++;
    }

    _insertNode(node, value) {
        // Standard BST insertion
        if (!node) {
            return new AVLNode(value);
        }

        if (value < node.value) {
            node.left = this._insertNode(node.left, value);
        } else if (value > node.value) {
            node.right = this._insertNode(node.right, value);
        } else {
            // Duplicate values not allowed
            return node;
        }

        // Update height
        this._updateHeight(node);

        // Get balance factor
        const balance = this._getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node.left.value) {
            return this._rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && value > node.right.value) {
            return this._rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && value > node.left.value) {
            node.left = this._rotateLeft(node.left);
            return this._rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node.right.value) {
            node.right = this._rotateRight(node.right);
            return this._rotateLeft(node);
        }

        return node;
    }

    /**
     * Delete value from AVL tree
     * @param {number} value - Value to delete
     * @returns {boolean} True if deleted
     */
    delete(value) {
        const initialSize = this.size;
        this.root = this._deleteNode(this.root, value);
        return this.size < initialSize;
    }

    _deleteNode(node, value) {
        if (!node) return null;

        // Standard BST deletion
        if (value < node.value) {
            node.left = this._deleteNode(node.left, value);
        } else if (value > node.value) {
            node.right = this._deleteNode(node.right, value);
        } else {
            // Node to be deleted found
            this.size--;

            // Node with only one child or no child
            if (!node.left || !node.right) {
                return node.left || node.right;
            }

            // Node with two children
            const minRight = this._findMin(node.right);
            node.value = minRight.value;
            node.right = this._deleteNode(node.right, minRight.value);
            this.size++; // Compensate for double decrement
        }

        // Update height
        this._updateHeight(node);

        // Get balance factor
        const balance = this._getBalance(node);

        // Left Left Case
        if (balance > 1 && this._getBalance(node.left) >= 0) {
            return this._rotateRight(node);
        }

        // Left Right Case
        if (balance > 1 && this._getBalance(node.left) < 0) {
            node.left = this._rotateLeft(node.left);
            return this._rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && this._getBalance(node.right) <= 0) {
            return this._rotateLeft(node);
        }

        // Right Left Case
        if (balance < -1 && this._getBalance(node.right) > 0) {
            node.right = this._rotateRight(node.right);
            return this._rotateLeft(node);
        }

        return node;
    }

    /**
     * Find minimum value node in subtree
     * @private
     */
    _findMin(node) {
        while (node.left) {
            node = node.left;
        }
        return node;
    }

    /**
     * Search for value in tree
     * @param {number} value - Value to search
     * @returns {boolean}
     */
    search(value) {
        return this._searchNode(this.root, value);
    }

    _searchNode(node, value) {
        if (!node) return false;
        if (value === node.value) return true;
        if (value < node.value) return this._searchNode(node.left, value);
        return this._searchNode(node.right, value);
    }

    /**
     * Find minimum value in tree
     * @returns {number|null}
     */
    findMin() {
        if (!this.root) return null;
        return this._findMin(this.root).value;
    }

    /**
     * Find maximum value in tree
     * @returns {number|null}
     */
    findMax() {
        if (!this.root) return null;
        let node = this.root;
        while (node.right) {
            node = node.right;
        }
        return node.value;
    }

    /**
     * Get height of tree
     * @returns {number}
     */
    getHeight() {
        return this._getHeight(this.root);
    }

    /**
     * Check if tree is balanced
     * @returns {boolean}
     */
    isBalanced() {
        return this._checkBalance(this.root);
    }

    _checkBalance(node) {
        if (!node) return true;

        const balance = Math.abs(this._getBalance(node));
        if (balance > 1) return false;

        return this._checkBalance(node.left) && this._checkBalance(node.right);
    }

    /**
     * In-order traversal
     * @returns {number[]}
     */
    inorder() {
        const result = [];
        this._inorderTraversal(this.root, result);
        return result;
    }

    _inorderTraversal(node, result) {
        if (node) {
            this._inorderTraversal(node.left, result);
            result.push(node.value);
            this._inorderTraversal(node.right, result);
        }
    }

    /**
     * Pre-order traversal
     * @returns {number[]}
     */
    preorder() {
        const result = [];
        this._preorderTraversal(this.root, result);
        return result;
    }

    _preorderTraversal(node, result) {
        if (node) {
            result.push(node.value);
            this._preorderTraversal(node.left, result);
            this._preorderTraversal(node.right, result);
        }
    }

    /**
     * Post-order traversal
     * @returns {number[]}
     */
    postorder() {
        const result = [];
        this._postorderTraversal(this.root, result);
        return result;
    }

    _postorderTraversal(node, result) {
        if (node) {
            this._postorderTraversal(node.left, result);
            this._postorderTraversal(node.right, result);
            result.push(node.value);
        }
    }

    /**
     * Level-order traversal
     * @returns {number[]}
     */
    levelOrder() {
        if (!this.root) return [];

        const result = [];
        const queue = [this.root];

        while (queue.length > 0) {
            const node = queue.shift();
            result.push(node.value);

            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }

        return result;
    }

    /**
     * Get number of nodes in tree
     * @returns {number}
     */
    getSize() {
        return this.size;
    }

    /**
     * Check if tree is empty
     * @returns {boolean}
     */
    isEmpty() {
        return this.size === 0;
    }

    /**
     * Clear all nodes from tree
     */
    clear() {
        this.root = null;
        this.size = 0;
    }

    /**
     * Find kth smallest element
     * @param {number} k - Position (1-based)
     * @returns {number|null}
     */
    kthSmallest(k) {
        const arr = this.inorder();
        return k > 0 && k <= arr.length ? arr[k - 1] : null;
    }

    /**
     * Visualize tree structure
     * @returns {string}
     */
    visualize() {
        const lines = [];
        this._visualizeHelper(this.root, '', true, lines);
        return lines.join('\n');
    }

    _visualizeHelper(node, prefix, isLeft, lines) {
        if (!node) return;

        lines.push(prefix + (isLeft ? '├── ' : '└── ') + 
                  `${node.value} (h:${node.height}, b:${this._getBalance(node)})`);

        if (node.left || node.right) {
            if (node.left) {
                this._visualizeHelper(node.left, prefix + (isLeft ? '│   ' : '    '), true, lines);
            } else {
                lines.push(prefix + (isLeft ? '│   ' : '    ') + '├── null');
            }

            if (node.right) {
                this._visualizeHelper(node.right, prefix + (isLeft ? '│   ' : '    '), false, lines);
            } else {
                lines.push(prefix + (isLeft ? '│   ' : '    ') + '└── null');
            }
        }
    }

    /**
     * Range query - find all values in range [min, max]
     * @param {number} min - Minimum value
     * @param {number} max - Maximum value
     * @returns {number[]}
     */
    rangeQuery(min, max) {
        const result = [];
        this._rangeQueryHelper(this.root, min, max, result);
        return result;
    }

    _rangeQueryHelper(node, min, max, result) {
        if (!node) return;

        if (node.value > min) {
            this._rangeQueryHelper(node.left, min, max, result);
        }

        if (node.value >= min && node.value <= max) {
            result.push(node.value);
        }

        if (node.value < max) {
            this._rangeQueryHelper(node.right, min, max, result);
        }
    }
}

// Test cases
console.log('=== AVL Tree Operations ===');
const avl = new AVLTree();

// Insert values
const values = [10, 20, 30, 40, 50, 25];
console.log('Inserting:', values.join(', '));
values.forEach(val => avl.insert(val));

console.log('\nTree structure:');
console.log(avl.visualize());

console.log('\nTraversals:');
console.log('In-order:', avl.inorder()); // Sorted
console.log('Pre-order:', avl.preorder());
console.log('Level-order:', avl.levelOrder());

console.log('\nTree properties:');
console.log('Size:', avl.getSize());
console.log('Height:', avl.getHeight());
console.log('Is balanced:', avl.isBalanced());
console.log('Min value:', avl.findMin());
console.log('Max value:', avl.findMax());

console.log('\nSearch operations:');
console.log('Search 25:', avl.search(25)); // true
console.log('Search 15:', avl.search(15)); // false

console.log('\nKth smallest:');
console.log('3rd smallest:', avl.kthSmallest(3)); // 30

console.log('\nRange query [20, 40]:', avl.rangeQuery(20, 40));

console.log('\nDeleting 20...');
avl.delete(20);
console.log('In-order after deletion:', avl.inorder());
console.log('Is still balanced:', avl.isBalanced());

module.exports = AVLTree;
