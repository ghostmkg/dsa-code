from heapq import heappush, heappop
from collections import Counter

def rearrangeString(s: str) -> str:
    freq = Counter(s)
    n = len(s)
    
    # If impossible condition
    if max(freq.values()) > (n + 1) // 2:
        return "IMPOSSIBLE"
    
    # Max heap by frequency, then lexicographically smallest char
    heap = []
    for ch, f in freq.items():
        heappush(heap, (-f, ch))
    
    prev = None
    result = []
    
    while heap:
        f1, ch1 = heappop(heap)
        result.append(ch1)
        
        # If previous still has frequency left, push it back
        if prev:
            heappush(heap, prev)
            prev = None
        
        # Reduce frequency and hold current if more remain
        if -f1 > 1:
            prev = (f1 + 1, ch1)  # since f1 is negative
    
    rearranged = "".join(result)
    
    # Final check for adjacency (safety)
    for i in range(1, len(rearranged)):
        if rearranged[i] == rearranged[i - 1]:
            return "IMPOSSIBLE"
    
    return rearranged

# Example test
if __name__ == "__main__":
    print(rearrangeString("aabb"))   # Output: abab
    print(rearrangeString("aaab"))   # Output: IMPOSSIBLE
    print(rearrangeString("aabc"))   # Output: abca
