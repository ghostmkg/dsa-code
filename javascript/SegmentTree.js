/**
 * Segment Tree Data Structure
 * 
 * Description: Tree structure for storing intervals or segments. Allows querying
 * which segments contain a given point efficiently.
 * 
 * Time Complexity:
 * - Build: O(n)
 * - Query: O(log n)
 * - Update: O(log n)
 * 
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - Range queries (sum, min, max)
 * - Range updates
 * - Computational geometry
 * - Database query optimization
 * 
 * Example:
 * segTree.query(1, 3);  // Get sum/min/max from index 1 to 3
 * segTree.update(2, 10); // Update index 2 to value 10
 */

class SegmentTree {
    constructor(arr, operation = 'sum') {
        this.n = arr.length;
        this.arr = [...arr];
        this.tree = new Array(4 * this.n);
        this.operation = operation;
        
        // Set identity value based on operation
        this.identity = this._getIdentity();
        
        if (this.n > 0) {
            this.build(0, 0, this.n - 1);
        }
    }

    _getIdentity() {
        switch (this.operation) {
            case 'sum': return 0;
            case 'min': return Infinity;
            case 'max': return -Infinity;
            case 'product': return 1;
            case 'gcd': return 0;
            default: return 0;
        }
    }

    _merge(a, b) {
        switch (this.operation) {
            case 'sum': return a + b;
            case 'min': return Math.min(a, b);
            case 'max': return Math.max(a, b);
            case 'product': return a * b;
            case 'gcd': return this._gcd(a, b);
            default: return a + b;
        }
    }

    _gcd(a, b) {
        return b === 0 ? a : this._gcd(b, a % b);
    }

    /**
     * Build segment tree
     * @private
     */
    build(node, start, end) {
        if (start === end) {
            this.tree[node] = this.arr[start];
            return;
        }

        const mid = Math.floor((start + end) / 2);
        const leftChild = 2 * node + 1;
        const rightChild = 2 * node + 2;

        this.build(leftChild, start, mid);
        this.build(rightChild, mid + 1, end);

        this.tree[node] = this._merge(this.tree[leftChild], this.tree[rightChild]);
    }

    /**
     * Query range [left, right]
     * @param {number} left - Start index
     * @param {number} right - End index
     * @returns {number} Result based on operation
     */
    query(left, right) {
        if (left < 0 || right >= this.n || left > right) {
            throw new Error('Invalid query range');
        }
        return this._query(0, 0, this.n - 1, left, right);
    }

    _query(node, start, end, left, right) {
        // No overlap
        if (start > right || end < left) {
            return this.identity;
        }

        // Complete overlap
        if (start >= left && end <= right) {
            return this.tree[node];
        }

        // Partial overlap
        const mid = Math.floor((start + end) / 2);
        const leftChild = 2 * node + 1;
        const rightChild = 2 * node + 2;

        const leftResult = this._query(leftChild, start, mid, left, right);
        const rightResult = this._query(rightChild, mid + 1, end, left, right);

        return this._merge(leftResult, rightResult);
    }

    /**
     * Update value at index
     * @param {number} index - Index to update
     * @param {number} value - New value
     */
    update(index, value) {
        if (index < 0 || index >= this.n) {
            throw new Error('Invalid index');
        }
        this.arr[index] = value;
        this._update(0, 0, this.n - 1, index, value);
    }

    _update(node, start, end, index, value) {
        if (start === end) {
            this.tree[node] = value;
            return;
        }

        const mid = Math.floor((start + end) / 2);
        const leftChild = 2 * node + 1;
        const rightChild = 2 * node + 2;

        if (index <= mid) {
            this._update(leftChild, start, mid, index, value);
        } else {
            this._update(rightChild, mid + 1, end, index, value);
        }

        this.tree[node] = this._merge(this.tree[leftChild], this.tree[rightChild]);
    }

    /**
     * Range update - add value to all elements in range
     * @param {number} left - Start index
     * @param {number} right - End index
     * @param {number} value - Value to add
     */
    rangeUpdate(left, right, value) {
        for (let i = left; i <= right; i++) {
            this.update(i, this.arr[i] + value);
        }
    }

    /**
     * Get original array
     * @returns {number[]}
     */
    getArray() {
        return [...this.arr];
    }

    /**
     * Get size of array
     * @returns {number}
     */
    size() {
        return this.n;
    }

    /**
     * Find index of first element >= value in range
     * @param {number} left - Start index
     * @param {number} right - End index
     * @param {number} value - Target value
     * @returns {number} Index or -1 if not found
     */
    lowerBound(left, right, value) {
        for (let i = left; i <= right; i++) {
            if (this.arr[i] >= value) return i;
        }
        return -1;
    }

    /**
     * Visualize segment tree
     * @returns {string}
     */
    visualize() {
        const lines = [];
        const visualizeHelper = (node, start, end, prefix = '', isLeft = true) => {
            if (start > end) return;

            const marker = isLeft ? '├── ' : '└── ';
            const range = start === end ? `[${start}]` : `[${start}-${end}]`;
            lines.push(prefix + marker + `${range}: ${this.tree[node]}`);

            if (start !== end) {
                const mid = Math.floor((start + end) / 2);
                const newPrefix = prefix + (isLeft ? '│   ' : '    ');
                visualizeHelper(2 * node + 1, start, mid, newPrefix, true);
                visualizeHelper(2 * node + 2, mid + 1, end, newPrefix, false);
            }
        };

        lines.push('Segment Tree:');
        visualizeHelper(0, 0, this.n - 1);
        return lines.join('\n');
    }
}

// Lazy Propagation Segment Tree (for efficient range updates)
class LazySegmentTree extends SegmentTree {
    constructor(arr, operation = 'sum') {
        super(arr, operation);
        this.lazy = new Array(4 * this.n).fill(0);
    }

    _push(node, start, end) {
        if (this.lazy[node] !== 0) {
            this.tree[node] += this.lazy[node] * (end - start + 1);

            if (start !== end) {
                this.lazy[2 * node + 1] += this.lazy[node];
                this.lazy[2 * node + 2] += this.lazy[node];
            }

            this.lazy[node] = 0;
        }
    }

    rangeUpdate(left, right, value) {
        this._rangeUpdate(0, 0, this.n - 1, left, right, value);
    }

    _rangeUpdate(node, start, end, left, right, value) {
        this._push(node, start, end);

        if (start > right || end < left) return;

        if (start >= left && end <= right) {
            this.lazy[node] += value;
            this._push(node, start, end);
            return;
        }

        const mid = Math.floor((start + end) / 2);
        this._rangeUpdate(2 * node + 1, start, mid, left, right, value);
        this._rangeUpdate(2 * node + 2, mid + 1, end, left, right, value);

        this._push(2 * node + 1, start, mid);
        this._push(2 * node + 2, mid + 1, end);
        this.tree[node] = this.tree[2 * node + 1] + this.tree[2 * node + 2];
    }

    query(left, right) {
        return this._lazyQuery(0, 0, this.n - 1, left, right);
    }

    _lazyQuery(node, start, end, left, right) {
        this._push(node, start, end);

        if (start > right || end < left) {
            return this.identity;
        }

        if (start >= left && end <= right) {
            return this.tree[node];
        }

        const mid = Math.floor((start + end) / 2);
        const leftResult = this._lazyQuery(2 * node + 1, start, mid, left, right);
        const rightResult = this._lazyQuery(2 * node + 2, mid + 1, end, left, right);

        return this._merge(leftResult, rightResult);
    }
}

// Test cases
console.log('=== Range Sum Queries ===');
const arr = [1, 3, 5, 7, 9, 11];
const segTree = new SegmentTree(arr, 'sum');

console.log('Array:', arr);
console.log('Sum [1, 3]:', segTree.query(1, 3)); // 3+5+7 = 15
console.log('Sum [0, 5]:', segTree.query(0, 5)); // 1+3+5+7+9+11 = 36

segTree.update(2, 10);
console.log('After updating index 2 to 10:');
console.log('Sum [1, 3]:', segTree.query(1, 3)); // 3+10+7 = 20

console.log('\n=== Range Min Queries ===');
const minTree = new SegmentTree(arr, 'min');
console.log('Min [1, 4]:', minTree.query(1, 4)); // min(3,5,7,9) = 3

console.log('\n=== Range Max Queries ===');
const maxTree = new SegmentTree(arr, 'max');
console.log('Max [1, 4]:', maxTree.query(1, 4)); // max(3,5,7,9) = 9

console.log('\n=== Lazy Propagation ===');
const lazyTree = new LazySegmentTree([1, 2, 3, 4, 5], 'sum');
console.log('Initial sum [0, 4]:', lazyTree.query(0, 4)); // 15
lazyTree.rangeUpdate(1, 3, 10);
console.log('After adding 10 to [1,3]:', lazyTree.query(0, 4)); // 1+12+13+14+5 = 45

console.log('\n' + segTree.visualize());

module.exports = { SegmentTree, LazySegmentTree };
