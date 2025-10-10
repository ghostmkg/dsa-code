class SegmentTree:
    """
    Segment Tree for range queries and point updates.
    Supports range sum, min, max queries.
    
    Time Complexity:
        - Build: O(n)
        - Query: O(log n)
        - Update: O(log n)
    Space: O(4n)
    """
    
    def __init__(self, arr, operation='sum'):
        """
        Initialize segment tree.
        
        Args:
            arr: input array
            operation: 'sum', 'min', or 'max'
        """
        self.n = len(arr)
        self.arr = arr[:]
        self.tree = [0] * (4 * self.n)
        self.operation = operation
        
        if operation == 'sum':
            self.default = 0
            self.op = lambda a, b: a + b
        elif operation == 'min':
            self.default = float('inf')
            self.op = min
        elif operation == 'max':
            self.default = float('-inf')
            self.op = max
        
        self._build(0, 0, self.n - 1)
    
    def _build(self, node, left, right):
        """Build the segment tree recursively"""
        if left == right:
            self.tree[node] = self.arr[left]
            return
        
        mid = (left + right) // 2
        self._build(2 * node + 1, left, mid)
        self._build(2 * node + 2, mid + 1, right)
        
        self.tree[node] = self.op(
            self.tree[2 * node + 1],
            self.tree[2 * node + 2]
        )
    
    def query(self, ql, qr):
        """
        Query the range [ql, qr] (inclusive).
        
        Args:
            ql: query left bound
            qr: query right bound
        
        Returns:
            result based on operation (sum/min/max)
        """
        return self._query(0, 0, self.n - 1, ql, qr)
    
    def _query(self, node, left, right, ql, qr):
        """Helper for range query"""
        # No overlap
        if left > qr or right < ql:
            return self.default
        
        # Complete overlap
        if left >= ql and right <= qr:
            return self.tree[node]
        
        # Partial overlap
        mid = (left + right) // 2
        left_result = self._query(2 * node + 1, left, mid, ql, qr)
        right_result = self._query(2 * node + 2, mid + 1, right, ql, qr)
        
        return self.op(left_result, right_result)
    
    def update(self, index, value):
        """
        Update value at index.
        
        Args:
            index: position to update
            value: new value
        """
        self.arr[index] = value
        self._update(0, 0, self.n - 1, index, value)
    
    def _update(self, node, left, right, index, value):
        """Helper for point update"""
        if left == right:
            self.tree[node] = value
            return
        
        mid = (left + right) // 2
        
        if index <= mid:
            self._update(2 * node + 1, left, mid, index, value)
        else:
            self._update(2 * node + 2, mid + 1, right, index, value)
        
        self.tree[node] = self.op(
            self.tree[2 * node + 1],
            self.tree[2 * node + 2]
        )


# Example usage
if __name__ == "__main__":
    # Example 1: Range Sum Query
    arr = [1, 3, 5, 7, 9, 11]
    seg_tree = SegmentTree(arr, operation='sum')
    
    print(f"Sum of range [1, 3]: {seg_tree.query(1, 3)}")  # 3+5+7 = 15
    print(f"Sum of range [0, 5]: {seg_tree.query(0, 5)}")  # 36
    
    # Update and query
    seg_tree.update(1, 10)
    print(f"After update, sum [1, 3]: {seg_tree.query(1, 3)}")  # 10+5+7 = 22
    
    # Example 2: Range Minimum Query
    arr2 = [5, 2, 8, 1, 9, 3]
    min_tree = SegmentTree(arr2, operation='min')
    
    print(f"\nMin of range [0, 3]: {min_tree.query(0, 3)}")  # 1
    print(f"Min of range [2, 5]: {min_tree.query(2, 5)}")  # 1
    
    min_tree.update(3, 6)
    print(f"After update, min [0, 3]: {min_tree.query(0, 3)}")  # 2
    
    # Example 3: Range Maximum Query
    arr3 = [3, 1, 7, 2, 9, 4]
    max_tree = SegmentTree(arr3, operation='max')
    
    print(f"\nMax of range [1, 4]: {max_tree.query(1, 4)}")  # 9
    print(f"Max of range [0, 2]: {max_tree.query(0, 2)}")  # 7