"""
Suffix Array with LCP (Longest Common Prefix) Implementation

Problem: String Processing and Pattern Matching
Source: Classic String Algorithm
Approach: Suffix Array Construction + LCP Array Computation
Time Complexity: O(n log n) for construction, O(m log n) for pattern search
Space Complexity: O(n) for suffix array and LCP array

The Suffix Array is a sorted array of all suffixes of a string, combined with
LCP array for efficient string processing operations.
"""

class SuffixArray:
    def __init__(self, text):
        """
        Initialize Suffix Array with given text
        
        Args:
            text (str): Input string to build suffix array from
        """
        self.text = text
        self.n = len(text)
        self.suffix_array = []
        self.lcp_array = []
        self.rank = []
        
        if self.n > 0:
            self._build_suffix_array()
            self._build_lcp_array()
    
    def _build_suffix_array(self):
        """Build suffix array using DC3 algorithm (simplified version)"""
        # For simplicity, we'll use a basic O(n^2 log n) approach
        # In practice, DC3 or SA-IS algorithms are used for O(n log n)
        
        suffixes = []
        for i in range(self.n):
            suffixes.append((self.text[i:], i))
        
        # Sort suffixes lexicographically
        suffixes.sort()
        
        self.suffix_array = [suffix[1] for suffix in suffixes]
        self.rank = [0] * self.n
        
        for i, (_, pos) in enumerate(suffixes):
            self.rank[pos] = i
    
    def _build_lcp_array(self):
        """Build LCP array using Kasai's algorithm"""
        self.lcp_array = [0] * (self.n - 1)
        
        h = 0
        for i in range(self.n):
            if self.rank[i] == 0:
                h = 0
                continue
            
            j = self.suffix_array[self.rank[i] - 1]
            
            # Find LCP between current suffix and previous suffix
            while (i + h < self.n and 
                   j + h < self.n and 
                   self.text[i + h] == self.text[j + h]):
                h += 1
            
            self.lcp_array[self.rank[i] - 1] = h
            
            if h > 0:
                h -= 1
    
    def get_suffix_array(self):
        """Get the suffix array"""
        return self.suffix_array.copy()
    
    def get_lcp_array(self):
        """Get the LCP array"""
        return self.lcp_array.copy()
    
    def get_suffixes(self):
        """Get all suffixes in sorted order"""
        suffixes = []
        for i in self.suffix_array:
            suffixes.append(self.text[i:])
        return suffixes
    
    def search_pattern(self, pattern):
        """
        Search for pattern in text using suffix array
        
        Args:
            pattern (str): Pattern to search for
            
        Returns:
            list: List of starting positions where pattern is found
        """
        if not pattern:
            return list(range(self.n))
        
        # Binary search for pattern
        left = 0
        right = self.n - 1
        
        # Find leftmost occurrence
        while left <= right:
            mid = (left + right) // 2
            suffix = self.text[self.suffix_array[mid]:]
            
            if pattern <= suffix:
                right = mid - 1
            else:
                left = mid + 1
        
        start = left
        
        # Find rightmost occurrence
        left = 0
        right = self.n - 1
        
        while left <= right:
            mid = (left + right) // 2
            suffix = self.text[self.suffix_array[mid]:]
            
            if pattern < suffix:
                right = mid - 1
            else:
                left = mid + 1
        
        end = right
        
        # Extract positions
        positions = []
        for i in range(start, end + 1):
            positions.append(self.suffix_array[i])
        
        return sorted(positions)
    
    def longest_common_substring(self, other_text):
        """
        Find longest common substring between self.text and other_text
        
        Args:
            other_text (str): Another string to compare with
            
        Returns:
            str: Longest common substring
        """
        # Combine texts with separator
        separator = '$'
        combined = self.text + separator + other_text
        
        # Build suffix array for combined text
        combined_sa = SuffixArray(combined)
        
        max_length = 0
        max_substring = ""
        
        # Find longest common substring
        for i in range(len(combined_sa.lcp_array)):
            if combined_sa.lcp_array[i] > max_length:
                # Check if suffixes belong to different original strings
                pos1 = combined_sa.suffix_array[i]
                pos2 = combined_sa.suffix_array[i + 1]
                
                # Check if one suffix is from first string and other from second
                if ((pos1 < len(self.text) and pos2 >= len(self.text) + 1) or
                    (pos2 < len(self.text) and pos1 >= len(self.text) + 1)):
                    
                    max_length = combined_sa.lcp_array[i]
                    max_substring = combined[pos1:pos1 + max_length]
        
        return max_substring
    
    def longest_repeated_substring(self):
        """
        Find longest repeated substring in the text
        
        Returns:
            str: Longest repeated substring
        """
        max_length = 0
        max_substring = ""
        
        for i in range(len(self.lcp_array)):
            if self.lcp_array[i] > max_length:
                max_length = self.lcp_array[i]
                pos = self.suffix_array[i]
                max_substring = self.text[pos:pos + max_length]
        
        return max_substring
    
    def distinct_substrings_count(self):
        """
        Count total number of distinct substrings
        
        Returns:
            int: Number of distinct substrings
        """
        total_substrings = self.n * (self.n + 1) // 2
        repeated_substrings = sum(self.lcp_array)
        
        return total_substrings - repeated_substrings
    
    def get_all_substrings(self):
        """
        Get all distinct substrings
        
        Returns:
            set: Set of all distinct substrings
        """
        substrings = set()
        
        for i in range(self.n):
            for j in range(i + 1, self.n + 1):
                substrings.add(self.text[i:j])
        
        return substrings
    
    def print_suffix_array(self):
        """Print suffix array with suffixes"""
        print("Suffix Array:")
        print("Index\tSuffix")
        print("-" * 30)
        
        for i, pos in enumerate(self.suffix_array):
            suffix = self.text[pos:]
            print(f"{i:2d}\t{pos:2d}\t{suffix}")
    
    def print_lcp_array(self):
        """Print LCP array"""
        print("\nLCP Array:")
        print("Index\tLCP\tSuffixes")
        print("-" * 40)
        
        for i, lcp in enumerate(self.lcp_array):
            if i < len(self.suffix_array) - 1:
                suffix1 = self.text[self.suffix_array[i]:]
                suffix2 = self.text[self.suffix_array[i + 1]:]
                print(f"{i:2d}\t{lcp:2d}\t{suffix1} | {suffix2}")
    
    def visualize(self):
        """Visualize suffix array and LCP array"""
        print(f"\n=== Suffix Array Visualization ===")
        print(f"Text: '{self.text}'")
        print(f"Length: {self.n}")
        
        self.print_suffix_array()
        self.print_lcp_array()
        
        print(f"\nLongest Repeated Substring: '{self.longest_repeated_substring()}'")
        print(f"Distinct Substrings Count: {self.distinct_substrings_count()}")


class AdvancedSuffixArray(SuffixArray):
    """Advanced Suffix Array with additional functionality"""
    
    def __init__(self, text):
        super().__init__(text)
        self._build_enhanced_data_structures()
    
    def _build_enhanced_data_structures(self):
        """Build additional data structures for advanced operations"""
        # Build inverse suffix array
        self.inverse_sa = [0] * self.n
        for i in range(self.n):
            self.inverse_sa[self.suffix_array[i]] = i
        
        # Build LCP range minimum query structure
        self._build_rmq_structure()
    
    def _build_rmq_structure(self):
        """Build Range Minimum Query structure for LCP array"""
        # Simple implementation - in practice, use Segment Tree or Sparse Table
        self.rmq = []
        self.rmq.append(self.lcp_array.copy())
        
        k = 1
        while (1 << k) <= len(self.lcp_array):
            self.rmq.append([0] * (len(self.lcp_array) - (1 << k) + 1))
            for i in range(len(self.rmq[k])):
                self.rmq[k][i] = min(
                    self.rmq[k-1][i],
                    self.rmq[k-1][i + (1 << (k-1))]
                )
            k += 1
    
    def lcp_range_minimum(self, i, j):
        """Find minimum LCP in range [i, j]"""
        if i > j or i < 0 or j >= len(self.lcp_array):
            return 0
        
        length = j - i + 1
        k = 0
        while (1 << (k + 1)) <= length:
            k += 1
        
        return min(
            self.rmq[k][i],
            self.rmq[k][j - (1 << k) + 1]
        )
    
    def longest_common_prefix(self, i, j):
        """Find longest common prefix between suffixes at positions i and j"""
        if i == j:
            return self.n - self.suffix_array[i]
        
        if i > j:
            i, j = j, i
        
        return self.lcp_range_minimum(i, j - 1)
    
    def pattern_search_advanced(self, pattern):
        """Advanced pattern search with additional information"""
        positions = self.search_pattern(pattern)
        
        results = []
        for pos in positions:
            # Find all occurrences of this pattern
            suffix_pos = self.inverse_sa[pos]
            
            # Find range of suffixes with same prefix
            left = suffix_pos
            right = suffix_pos
            
            # Expand left
            while left > 0 and self.lcp_array[left - 1] >= len(pattern):
                left -= 1
            
            # Expand right
            while right < len(self.lcp_array) and self.lcp_array[right] >= len(pattern):
                right += 1
            
            # Get all positions in this range
            range_positions = []
            for i in range(left, right + 1):
                range_positions.append(self.suffix_array[i])
            
            results.append({
                'pattern': pattern,
                'positions': sorted(range_positions),
                'count': len(range_positions),
                'range': (left, right)
            })
        
        return results


def demo_suffix_array():
    """Demo function to showcase Suffix Array functionality"""
    print("=== Suffix Array with LCP Demo ===\n")
    
    # Test cases
    test_cases = [
        "banana",
        "mississippi",
        "abracadabra",
        "hello",
        "a",
        "aa",
        "aaa",
        "",
        "abcdef",
        "racecar"
    ]
    
    for i, text in enumerate(test_cases):
        print(f"Test Case {i + 1}: '{text}'")
        
        if not text:
            print("Empty string - skipping")
            print("-" * 50)
            continue
        
        # Create suffix array
        sa = SuffixArray(text)
        
        # Basic information
        print(f"Length: {sa.n}")
        print(f"Distinct substrings: {sa.distinct_substrings_count()}")
        print(f"Longest repeated substring: '{sa.longest_repeated_substring()}'")
        
        # Pattern search examples
        if len(text) > 2:
            pattern = text[:2]  # First two characters as pattern
            positions = sa.search_pattern(pattern)
            print(f"Pattern '{pattern}' found at positions: {positions}")
        
        # Show suffix array (for shorter strings)
        if len(text) <= 10:
            sa.visualize()
        
        print("-" * 50)
    
    # Advanced features demo
    print("\n=== Advanced Features Demo ===")
    
    text1 = "banana"
    text2 = "ananas"
    
    print(f"Text 1: '{text1}'")
    print(f"Text 2: '{text2}'")
    
    sa1 = AdvancedSuffixArray(text1)
    sa2 = AdvancedSuffixArray(text2)
    
    # Longest common substring
    lcs = sa1.longest_common_substring(text2)
    print(f"Longest common substring: '{lcs}'")
    
    # Pattern search with advanced info
    pattern = "an"
    results = sa1.pattern_search_advanced(pattern)
    print(f"Advanced search for '{pattern}':")
    for result in results:
        print(f"  Positions: {result['positions']}")
        print(f"  Count: {result['count']}")
        print(f"  Range: {result['range']}")
    
    # Performance test
    print("\n=== Performance Test ===")
    import time
    
    large_text = "a" * 1000 + "b" * 1000 + "c" * 1000
    print(f"Testing with large text (length: {len(large_text)})")
    
    start_time = time.time()
    sa_large = SuffixArray(large_text)
    end_time = time.time()
    
    print(f"Construction time: {(end_time - start_time):.4f} seconds")
    print(f"Distinct substrings: {sa_large.distinct_substrings_count()}")
    
    # Pattern search performance
    pattern = "abc"
    start_time = time.time()
    positions = sa_large.search_pattern(pattern)
    end_time = time.time()
    
    print(f"Pattern '{pattern}' search time: {(end_time - start_time):.4f} seconds")
    print(f"Found at {len(positions)} positions")


if __name__ == "__main__":
    demo_suffix_array()
