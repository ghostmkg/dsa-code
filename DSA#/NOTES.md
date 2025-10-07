# DSA Notes

A compact collection of Data Structures & Algorithms notes, patterns, and study checklist.

## Table of Contents
- Purpose
- Study checklist
- Core data structures (summary)
- Common algorithms & patterns
- Time complexity quick reference
- Problem patterns and tips
- Recommended practice problems & resources

## Purpose
Keep short, high-value reminders for solving typical DSA problems during interview prep and practice.

## Study checklist
- [ ] Arrays & Strings basics
- [ ] Two pointers & sliding window patterns
- [ ] Linked lists (insert/delete/reverse)
- [ ] Stacks & queues
- [ ] Trees (BST, traversal, LCA)
- [ ] Graphs (BFS, DFS, shortest paths)
- [ ] Heaps & priority queues
- [ ] Hash tables / maps / sets
- [ ] Sorting & searching
- [ ] Dynamic programming (top-down & bottom-up)
- [ ] Greedy algorithms
- [ ] Backtracking
- [ ] Complexity analysis practice

## Core data structures (short)
- Array: contiguous memory, O(1) access, O(n) insert/delete worst-case.
- Linked List: O(1) insert/delete at known position, O(n) search/access.
- Stack/Queue: LIFO / FIFO, use for recursion elimination, scheduling.
- Hash map/set: average O(1) lookup/insert, watch for collisions and worst-case.
- Heap: O(log n) push/pop, used for top-k, priority scheduling.
- Tree (binary/AVL/Red-Black): hierarchical data, BST supports ordered ops O(h).
- Graph: adjacency list (sparse) vs matrix (dense).

## Common algorithms & patterns
- Two pointers: sorted arrays, pair-sum, remove duplicates, partitioning.
- Sliding window: subarray problems with variable window (max/min sum, num distinct).
- Fast & slow pointers: detect cycles, middle of list.
- DFS/BFS: tree/graph traversal, connected components, topological sort (Kahn/DFS).
- Dynamic Programming: identify state, transition, base case, iterative vs memoized.
- Greedy: pick local optimum, prove with exchange argument.
- Backtracking: generate combinations/permutations, search with pruning.
- Divide & conquer: mergesort, quicksort, binary search.

## Time complexity quick reference
- Access array by index: O(1)
- Search unsorted array: O(n)
- Binary search (sorted): O(log n)
- Insertion in array (shift): O(n)
- Hash table ops: average O(1)
- BST ops: O(h) (balanced: O(log n))
- Heap push/pop: O(log n)
- Merge sort / Heap sort: O(n log n)
- Quick sort: average O(n log n), worst O(n^2)
- DFS/BFS: O(V + E)
- DP (typical knapsack / longest common subsequence): O(n*m) depending on states

## Problem patterns & tips
- When you see "subarray" think sliding window or prefix sums.
- When asked for "k-th" or "top-k", use heaps or selection algorithms.
- When constraints are large (n up to 10^5+), avoid O(n^2) solutions.
- Use hash maps for frequency/count problems and two-sum variants.
- Convert recursive brute force to DP by identifying overlapping subproblems.
- Sketch small examples and invariants before coding.

## Recommended practice problems
- Arrays: Two Sum, 3Sum, Longest Subarray with Sum K
- Strings: Longest Palindromic Substring, Anagram grouping
- Linked List: Reverse Linked List, Detect Cycle, Merge K Sorted Lists
- Trees: Binary Tree Maximum Path Sum, Serialize/Deserialize
- Graphs: Course Schedule, Number of Islands, Dijkstra problems
- DP: Knapsack, Longest Increasing Subsequence, Edit Distance
- Backtracking: Permutations, Combination Sum

## Resources
- "Introduction to Algorithms" (CLRS) — deep theory
- "Algorithms" by Sedgewick — practical
- LeetCode / HackerRank / Codeforces for practice
- Grokking the Coding Interview (patterns)

---

