class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s in strs:
            count = [0] * 26  # Initialize a 26-length array for 'a' to 'z'
            for c in s:
                count[ord(c) - ord("a")] += 1  # Count each character
            
            # Use tuple(count) as a hashable key for grouping anagrams
            res[tuple(count)].append(s)
        
        return list(res.values())  # Convert dict_values to list
