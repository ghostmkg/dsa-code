class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        left = [[0] * 3 for _ in range(n)]
        right = [[0] * 3 for _ in range(n)]

        num, mask, count = 0, 0, 0
        for i in range(n - 1):
            binary = 1 << (ord(s[i]) - ord("a"))
            if not (mask & binary):
                count += 1
                if count <= k:
                    mask |= binary
                else:
                    num += 1
                    mask = binary
                    count = 1
            left[i + 1][0] = num
            left[i + 1][1] = mask
            left[i + 1][2] = count

        num, mask, count = 0, 0, 0
        for i in range(n - 1, 0, -1):
            binary = 1 << (ord(s[i]) - ord("a"))
            if not (mask & binary):
                count += 1
                if count <= k:
                    mask |= binary
                else:
                    num += 1
                    mask = binary
                    count = 1
            right[i - 1][0] = num
            right[i - 1][1] = mask
            right[i - 1][2] = count

        max_val = 0
        for i in range(n):
            seg = left[i][0] + right[i][0] + 2
            tot_mask = left[i][1] | right[i][1]
            tot_count = bin(tot_mask).count("1")
            if left[i][2] == k and right[i][2] == k and tot_count < 26:
                seg += 1
            elif min(tot_count + 1, 26) <= k:
                seg -= 1
            max_val = max(max_val, seg)
        return max_val