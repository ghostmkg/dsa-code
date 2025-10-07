from typing import List
import heapq


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 0:
            return 0
        dist = [[float("inf")] * n for _ in range(n)]
        dist[0][0] = grid[0][0]

        heap = [(grid[0][0], 0, 0)]
        d = [0, 1, 0, -1, 0]

        while heap:
            cur_max, r, c = heapq.heappop(heap)
            if cur_max > dist[r][c]:
                continue

            if r == n - 1 and c == n - 1:
                return cur_max

            for i in range(4):
                nr, nc = r + d[i], c + d[i + 1]
                if 0 <= nr < n and 0 <= nc < n:
                    next_max = max(cur_max, grid[nr][nc])
                    if next_max < dist[nr][nc]:
                        dist[nr][nc] = next_max
                        heapq.heappush(heap, (next_max, nr, nc))

        return -1
        

if __name__ == "__main__":
    s = Solution()

    grid1 = [[0, 2], [1, 3]]
    print("Input:", grid1)
    print("Output:", s.swimInWater(grid1), "Expected:", 3)
    print()

    grid2 = [
        [0, 1, 2, 3, 4],
        [24, 23, 22, 21, 5],
        [12, 13, 14, 15, 16],
        [11, 17, 18, 19, 20],
        [10, 9, 8, 7, 6],
    ]
    print("Input:", grid2)
    print("Output:", s.swimInWater(grid2), "Expected:", 16)
