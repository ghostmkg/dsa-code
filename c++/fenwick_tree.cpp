/*
Fenwick Tree (Binary Indexed Tree) Implementation in C++

A Fenwick Tree is a data structure that can efficiently update elements and 
calculate prefix sums in a table of numbers. It's particularly useful for:
- Range sum queries
- Range updates
- Inversion count problems
- Order statistics

Time Complexity:
- Update: O(log n)
- Query: O(log n)
- Construction: O(n log n)

Space Complexity: O(n)

Key Operations:
1. Update: Add a value to an element at index i
2. Query: Get sum of elements from index 1 to i (1-indexed)
3. Range Query: Get sum of elements from index i to j
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;
    
    // Get the least significant bit
    int lsb(int i) {
        return i & (-i);
    }
    
public:
    // Constructor
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);  // 1-indexed
    }
    
    // Constructor with initial array
    FenwickTree(const vector<int>& arr) {
        size = arr.size();
        tree.assign(size + 1, 0);
        
        // Build the tree
        for (int i = 0; i < size; i++) {
            update(i + 1, arr[i]);  // Convert to 1-indexed
        }
    }
    
    // Update: Add value to element at index i (1-indexed)
    void update(int i, long long value) {
        while (i <= size) {
            tree[i] += value;
            i += lsb(i);
        }
    }
    
    // Query: Get sum from index 1 to i (1-indexed)
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lsb(i);
        }
        return sum;
    }
    
    // Range Query: Get sum from index i to j (1-indexed)
    long long rangeQuery(int i, int j) {
        if (i > j) return 0;
        return query(j) - query(i - 1);
    }
    
    // Get value at index i (1-indexed)
    long long get(int i) {
        return rangeQuery(i, i);
    }
    
    // Set value at index i (1-indexed)
    void set(int i, long long value) {
        long long current = get(i);
        update(i, value - current);
    }
    
    // Get size of the tree
    int getSize() const {
        return size;
    }
    
    // Print the tree (for debugging)
    void print() {
        cout << "Fenwick Tree: ";
        for (int i = 1; i <= size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
    
    // Print prefix sums
    void printPrefixSums() {
        cout << "Prefix Sums: ";
        for (int i = 1; i <= size; i++) {
            cout << query(i) << " ";
        }
        cout << endl;
    }
};

// Advanced Fenwick Tree with range updates
class RangeFenwickTree {
private:
    FenwickTree tree1, tree2;
    int size;
    
public:
    RangeFenwickTree(int n) : tree1(n), tree2(n) {
        size = n;
    }
    
    // Range Update: Add value to all elements from index i to j (1-indexed)
    void rangeUpdate(int i, int j, long long value) {
        tree1.update(i, value);
        tree1.update(j + 1, -value);
        tree2.update(i, value * (i - 1));
        tree2.update(j + 1, -value * j);
    }
    
    // Point Update: Add value to element at index i (1-indexed)
    void update(int i, long long value) {
        rangeUpdate(i, i, value);
    }
    
    // Query: Get sum from index 1 to i (1-indexed)
    long long query(int i) {
        return tree1.query(i) * i - tree2.query(i);
    }
    
    // Range Query: Get sum from index i to j (1-indexed)
    long long rangeQuery(int i, int j) {
        if (i > j) return 0;
        return query(j) - query(i - 1);
    }
    
    // Get value at index i (1-indexed)
    long long get(int i) {
        return rangeQuery(i, i);
    }
};

// Utility functions for common problems

// Count inversions in an array using Fenwick Tree
long long countInversions(const vector<int>& arr) {
    int n = arr.size();
    
    // Coordinate compression
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
    FenwickTree ft(temp.size());
    long long inversions = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        // Find compressed value
        int compressed = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
        
        // Count elements smaller than current element
        inversions += ft.query(compressed - 1);
        
        // Add current element
        ft.update(compressed, 1);
    }
    
    return inversions;
}

// Find kth smallest element using Fenwick Tree
int findKthSmallest(const vector<int>& arr, int k) {
    int n = arr.size();
    
    // Coordinate compression
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
    FenwickTree ft(temp.size());
    
    // Add all elements
    for (int i = 0; i < n; i++) {
        int compressed = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
        ft.update(compressed, 1);
    }
    
    // Binary search for kth smallest
    int left = 1, right = temp.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (ft.query(mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return temp[left - 1];
}

// Demo function
void demoFenwickTree() {
    cout << "=== Fenwick Tree Implementation Demo ===\n\n";
    
    // Basic Fenwick Tree demo
    cout << "1. Basic Fenwick Tree Operations:\n";
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << "Initial array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    FenwickTree ft(arr);
    cout << "Tree after construction:\n";
    ft.print();
    ft.printPrefixSums();
    
    cout << "\nRange queries:\n";
    cout << "Sum from index 1 to 3: " << ft.rangeQuery(1, 3) << endl;
    cout << "Sum from index 2 to 5: " << ft.rangeQuery(2, 5) << endl;
    cout << "Sum from index 1 to 6: " << ft.rangeQuery(1, 6) << endl;
    
    cout << "\nUpdating index 2 by adding 5:\n";
    ft.update(2, 5);
    ft.printPrefixSums();
    cout << "New sum from index 1 to 3: " << ft.rangeQuery(1, 3) << endl;
    
    cout << "\nSetting index 4 to value 20:\n";
    ft.set(4, 20);
    ft.printPrefixSums();
    
    // Range Fenwick Tree demo
    cout << "\n2. Range Fenwick Tree Operations:\n";
    RangeFenwickTree rft(6);
    
    cout << "Adding 5 to range [2, 4]:\n";
    rft.rangeUpdate(2, 4, 5);
    cout << "Prefix sums: ";
    for (int i = 1; i <= 6; i++) {
        cout << rft.query(i) << " ";
    }
    cout << endl;
    
    cout << "Adding 3 to range [1, 3]:\n";
    rft.rangeUpdate(1, 3, 3);
    cout << "Prefix sums: ";
    for (int i = 1; i <= 6; i++) {
        cout << rft.query(i) << " ";
    }
    cout << endl;
    
    // Inversion count demo
    cout << "\n3. Inversion Count Demo:\n";
    vector<int> testArr = {5, 4, 3, 2, 1};
    cout << "Array: ";
    for (int x : testArr) cout << x << " ";
    cout << endl;
    cout << "Number of inversions: " << countInversions(testArr) << endl;
    
    // Kth smallest element demo
    cout << "\n4. Kth Smallest Element Demo:\n";
    vector<int> kthArr = {7, 10, 4, 3, 20, 15};
    cout << "Array: ";
    for (int x : kthArr) cout << x << " ";
    cout << endl;
    cout << "3rd smallest element: " << findKthSmallest(kthArr, 3) << endl;
    cout << "6th smallest element: " << findKthSmallest(kthArr, 6) << endl;
}

int main() {
    demoFenwickTree();
    return 0;
}
