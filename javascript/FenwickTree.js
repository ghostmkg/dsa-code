/**
 * Fenwick Tree (Binary Indexed Tree)
 * 
 * Description: Data structure that efficiently maintains cumulative frequency tables
 * and supports range queries and point updates in logarithmic time.
 * 
 * Time Complexity:
 * - Build: O(n log n) or O(n) optimized
 * - Query (prefix sum): O(log n)
 * - Update: O(log n)
 * - Range query: O(log n)
 * 
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - Cumulative frequency queries
 * - Dynamic ranking systems
 * - Inversion counting
 * - 2D range queries
 * 
 * Example:
 * fenwick.update(3, 5);  // Add 5 to index 3
 * fenwick.query(5);      // Get sum from 0 to 5
 * fenwick.rangeQuery(2, 5); // Get sum from 2 to 5
 */

class FenwickTree {
    constructor(size) {
        if (!Number.isInteger(size) || size < 0) {
            throw new Error('Size must be a non-negative integer');
        }
        this.size = size;
        this.tree = new Array(size + 1).fill(0);
    }

    /**
     * Build Fenwick tree from array (optimized O(n) construction)
     * @param {number[]} arr - Input array
     * @returns {FenwickTree}
     */
    static fromArray(arr) {
        const fenwick = new FenwickTree(arr.length);
        
        // Copy values
        for (let i = 0; i < arr.length; i++) {
            fenwick.tree[i + 1] = arr[i];
        }

        // Build tree in O(n)
        for (let i = 1; i <= arr.length; i++) {
            const j = i + (i & -i);
            if (j <= arr.length) {
                fenwick.tree[j] += fenwick.tree[i];
            }
        }

        return fenwick;
    }

    /**
     * Update value at index (add delta)
     * @param {number} index - 0-based index
     * @param {number} delta - Value to add
     */
    update(index, delta) {
        if (index < 0 || index >= this.size) {
            throw new Error('Index out of bounds');
        }

        index++; // Convert to 1-based indexing

        while (index <= this.size) {
            this.tree[index] += delta;
            index += index & (-index); // Add last set bit
        }
    }

    /**
     * Get prefix sum from 0 to index (inclusive)
     * @param {number} index - 0-based index
     * @returns {number}
     */
    query(index) {
        if (index < 0) return 0;
        if (index >= this.size) index = this.size - 1;

        index++; // Convert to 1-based indexing
        let sum = 0;

        while (index > 0) {
            sum += this.tree[index];
            index -= index & (-index); // Remove last set bit
        }

        return sum;
    }

    /**
     * Get sum in range [left, right] (inclusive)
     * @param {number} left - Start index
     * @param {number} right - End index
     * @returns {number}
     */
    rangeQuery(left, right) {
        if (left < 0 || right >= this.size || left > right) {
            throw new Error('Invalid range');
        }

        return this.query(right) - (left > 0 ? this.query(left - 1) : 0);
    }

    /**
     * Set value at index (replace, not add)
     * @param {number} index - 0-based index
     * @param {number} value - New value
     */
    set(index, value) {
        const currentValue = this.get(index);
        this.update(index, value - currentValue);
    }

    /**
     * Get value at specific index
     * @param {number} index - 0-based index
     * @returns {number}
     */
    get(index) {
        return this.rangeQuery(index, index);
    }

    /**
     * Find index with given cumulative frequency (Binary search on Fenwick tree)
     * @param {number} target - Target cumulative sum
     * @returns {number} Index or -1 if not found
     */
    findIndex(target) {
        let index = 0;
        let bitMask = 1;

        // Find highest power of 2 <= size
        while (bitMask <= this.size) bitMask <<= 1;
        bitMask >>= 1;

        while (bitMask > 0) {
            const nextIndex = index + bitMask;
            if (nextIndex <= this.size && this.tree[nextIndex] < target) {
                target -= this.tree[nextIndex];
                index = nextIndex;
            }
            bitMask >>= 1;
        }

        return index < this.size ? index : -1;
    }

    /**
     * Scale all values by a constant
     * @param {number} factor - Scaling factor
     */
    scale(factor) {
        for (let i = 1; i <= this.size; i++) {
            this.tree[i] *= factor;
        }
    }

    /**
     * Get total sum of all elements
     * @returns {number}
     */
    total() {
        return this.query(this.size - 1);
    }

    /**
     * Convert to array
     * @returns {number[]}
     */
    toArray() {
        const arr = [];
        for (let i = 0; i < this.size; i++) {
            arr.push(this.get(i));
        }
        return arr;
    }

    /**
     * Clear all values
     */
    clear() {
        this.tree.fill(0);
    }

    /**
     * Get string representation
     * @returns {string}
     */
    toString() {
        return `FenwickTree(${this.toArray().join(', ')})`;
    }
}

// 2D Fenwick Tree for 2D range queries
class FenwickTree2D {
    constructor(rows, cols) {
        this.rows = rows;
        this.cols = cols;
        this.tree = Array.from({ length: rows + 1 }, () => 
            new Array(cols + 1).fill(0)
        );
    }

    /**
     * Update value at position (row, col)
     * @param {number} row - Row index (0-based)
     * @param {number} col - Column index (0-based)
     * @param {number} delta - Value to add
     */
    update(row, col, delta) {
        row++; col++; // Convert to 1-based

        for (let i = row; i <= this.rows; i += i & (-i)) {
            for (let j = col; j <= this.cols; j += j & (-j)) {
                this.tree[i][j] += delta;
            }
        }
    }

    /**
     * Query sum from (0,0) to (row, col)
     * @param {number} row - Row index (0-based)
     * @param {number} col - Column index (0-based)
     * @returns {number}
     */
    query(row, col) {
        row++; col++; // Convert to 1-based
        let sum = 0;

        for (let i = row; i > 0; i -= i & (-i)) {
            for (let j = col; j > 0; j -= j & (-j)) {
                sum += this.tree[i][j];
            }
        }

        return sum;
    }

    /**
     * Query sum in rectangle from (r1,c1) to (r2,c2)
     * @param {number} r1 - Top row
     * @param {number} c1 - Left column
     * @param {number} r2 - Bottom row
     * @param {number} c2 - Right column
     * @returns {number}
     */
    rangeQuery(r1, c1, r2, c2) {
        return this.query(r2, c2) 
             - (r1 > 0 ? this.query(r1 - 1, c2) : 0)
             - (c1 > 0 ? this.query(r2, c1 - 1) : 0)
             + (r1 > 0 && c1 > 0 ? this.query(r1 - 1, c1 - 1) : 0);
    }
}

// Range Update Point Query Fenwick Tree
class RangeUpdateFenwickTree {
    constructor(size) {
        this.size = size;
        this.tree = new FenwickTree(size);
    }

    /**
     * Add delta to range [left, right]
     * @param {number} left - Start index
     * @param {number} right - End index
     * @param {number} delta - Value to add
     */
    rangeUpdate(left, right, delta) {
        this.tree.update(left, delta);
        if (right + 1 < this.size) {
            this.tree.update(right + 1, -delta);
        }
    }

    /**
     * Get value at index
     * @param {number} index
     * @returns {number}
     */
    query(index) {
        return this.tree.query(index);
    }
}

// Test cases
console.log('=== Basic Fenwick Tree ===');
const fenwick = FenwickTree.fromArray([1, 3, 5, 7, 9, 11]);

console.log('Original array:', fenwick.toArray());
console.log('Prefix sum [0-3]:', fenwick.query(3)); // 1+3+5+7 = 16
console.log('Range sum [2-4]:', fenwick.rangeQuery(2, 4)); // 5+7+9 = 21

fenwick.update(2, 5); // Add 5 to index 2
console.log('After adding 5 to index 2:', fenwick.toArray());
console.log('New range sum [2-4]:', fenwick.rangeQuery(2, 4)); // 10+7+9 = 26

fenwick.set(3, 20); // Set index 3 to 20
console.log('After setting index 3 to 20:', fenwick.toArray());

console.log('Total sum:', fenwick.total());

console.log('\n=== 2D Fenwick Tree ===');
const fenwick2D = new FenwickTree2D(4, 4);

// Update some values
fenwick2D.update(0, 0, 1);
fenwick2D.update(1, 1, 2);
fenwick2D.update(2, 2, 3);
fenwick2D.update(3, 3, 4);

console.log('Sum from (0,0) to (2,2):', fenwick2D.query(2, 2)); // 6
console.log('Rectangle sum (1,1) to (3,3):', fenwick2D.rangeQuery(1, 1, 3, 3)); // 9

console.log('\n=== Range Update Point Query ===');
const rupqTree = new RangeUpdateFenwickTree(5);
rupqTree.rangeUpdate(1, 3, 10);
console.log('Value at index 2:', rupqTree.query(2)); // 10
console.log('Value at index 4:', rupqTree.query(4)); // 0

module.exports = { FenwickTree, FenwickTree2D, RangeUpdateFenwickTree };
