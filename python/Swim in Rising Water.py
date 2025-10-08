"""
File: Swim in Rising Water.py
Problem: "Swim in Rising Water" (minimum time to reach bottom-right in rising water)
Author: ChatGPT (example, educational)

Description:
Given an N x N grid where grid[i][j] represents the elevation at square (i, j),
initially the water level is 0 and rises over time. At time t you can move into any
square with elevation <= t. You can move up/down/left/right. Return the minimum time
t such that you can reach from (0, 0) to (N-1, N-1).

Approach:
Primary: Dijkstra / priority queue where the "distance" is the maximum elevation
encountered along the path (so cost of a path = max of elevations along it).
We use a min-heap storing tuples (current_path_max_elevation, r, c), and expand
neighbors updating their best-known path_max_elevation. Complexity: O(N^2 log N^2).

Optional: Binary search on time + BFS to check feasibility (commented) — also common.
"""

from typing import List, Tuple
import heapq
import random
import sys


def swim_in_rising_water_dijkstra(grid: List[List[int]]) -> int:
    """
    Dijkstra-like solution.
    Each node's cost is the maximum elevation encountered on the path from (0,0) to that node.
    We want the minimum possible cost to reach (N-1, N-1).

    Args:
        grid: square matrix (N x N) of non-negative integers.

    Returns:
        Minimum time t to reach bottom-right corner.
    """
    if not grid or not grid[0]:
        raise ValueError("Grid must be non-empty")

    n = len(grid)
    # If N==1, we are already at target; need at least grid[0][0] time to step onto it.
    if n == 1:
        return grid[0][0]

    # Directions: up, down, left, right
    directions: List[Tuple[int, int]] = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # best[r][c] will store the minimal possible maximum-elevation to reach (r,c)
    best = [[float('inf')] * n for _ in range(n)]
    best[0][0] = grid[0][0]

    # Min-heap ordered by (current path max elevation, r, c)
    heap: List[Tuple[int, int, int]] = [(grid[0][0], 0, 0)]
    heapq.heapify(heap)

    while heap:
        cur_max, r, c = heapq.heappop(heap)

        # If this popped entry is worse than the best known, skip it (lazy deletion)
        if cur_max > best[r][c]:
            continue

        # If we reached target, cur_max is the answer (Dijkstra's property)
        if r == n - 1 and c == n - 1:
            return cur_max

        # Explore neighbors
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n:
                # To step into neighbor, the path cost becomes max(cur_max, grid[nr][nc])
                new_cost = max(cur_max, grid[nr][nc])
                if new_cost < best[nr][nc]:
                    best[nr][nc] = new_cost
                    heapq.heappush(heap, (new_cost, nr, nc))

    # The grid is connected so we should always return inside the loop for valid inputs.
    raise RuntimeError("Unable to reach target — this should not happen on valid input")


# Optional: Binary search + BFS method (kept for learning/comparison)
def swim_in_rising_water_binary_search(grid: List[List[int]]) -> int:
    """
    Alternative method. Binary search on time t:
    - For a candidate time mid, check via BFS/DFS whether a path exists using only cells <= mid.
    Complexity: O(N^2 log M) where M = max elevation range.

    Returns the minimal feasible t.
    """
    if not grid or not grid[0]:
        raise ValueError("Grid must be non-empty")
    n = len(grid)

    def can_reach_with_time(t: int) -> bool:
        # BFS from (0,0) over cells with elevation <= t
        if grid[0][0] > t:
            return False
        visited = [[False] * n for _ in range(n)]
        queue = [(0, 0)]
        visited[0][0] = True
        for r, c in queue:
            if r == n - 1 and c == n - 1:
                return True
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc] and grid[nr][nc] <= t:
                    visited[nr][nc] = True
                    queue.append((nr, nc))
        return False

    left = max(grid[0][0], grid[-1][-1])  # time must be at least these two, but left=0 is fine too
    right = max(max(row) for row in grid)
    # Alternatively start left=0 right=right; we'll still find the minimal feasible t
    left = 0
    while left < right:
        mid = (left + right) // 2
        if can_reach_with_time(mid):
            right = mid
        else:
            left = mid + 1
    return left


# ------------ Utility and CLI helpers (for testers/learners) --------------


def generate_random_grid(n: int, seed: int = None, max_val: int = None) -> List[List[int]]:
    """
    Generate an N x N grid with unique (or random) elevation values suitable for testing.
    If you want to simulate the original LeetCode constraints where grid contains a permutation
    of 0..N*N-1, set max_val to n*n - 1 and ensure uniqueness.
    """
    if seed is not None:
        random.seed(seed)

    if max_val is None:
        max_val = n * n - 1

    # To mimic LeetCode's test style (0..N*N-1 permutation), we can optionally shuffle.
    # Here we create random values in [0, max_val].
    grid = [[random.randint(0, max_val) for _ in range(n)] for _ in range(n)]
    return grid


def print_grid(grid: List[List[int]]):
    """
    Nicely print the grid in a readable format.
    """
    for row in grid:
        print(" ".join(f"{val:3d}" for val in row))
    print()


def run_examples_and_tests():
    """
    Run sample cases and small unit tests to verify correctness.
    """
    print("=== Swim in Rising Water — Examples and Tests ===\n")

    # Example 1 (classic)
    grid1 = [
        [0, 2],
        [1, 3]
    ]
    print("Grid 1:")
    print_grid(grid1)
    print("Dijkstra result (expected 3):", swim_in_rising_water_dijkstra(grid1))
    print("Binary search result (expected 3):", swim_in_rising_water_binary_search(grid1))
    print("-" * 40)

    # Example 2 (3x3 illustrative)
    grid2 = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8]
    ]
    print("Grid 2:")
    print_grid(grid2)
    print("Dijkstra result (expected 8):", swim_in_rising_water_dijkstra(grid2))
    print("Binary search result (expected 8):", swim_in_rising_water_binary_search(grid2))
    print("-" * 40)

    # Random tests — compare both approaches for small N
    for n in [1, 2, 3, 4, 5]:
        grid_rand = generate_random_grid(n, seed=42, max_val=n * n)
        print(f"Random Grid (n={n}):")
        print_grid(grid_rand)
        ans1 = swim_in_rising_water_dijkstra(grid_rand)
        ans2 = swim_in_rising_water_binary_search(grid_rand)
        print(f"Dijkstra: {ans1}  |  BinarySearch+BFS: {ans2}")
        assert ans1 == ans2, f"Mismatch for n={n}: {ans1} vs {ans2}"
        print("OK\n" + "-" * 40)

    print("All self-tests passed!")


# If module run as script: provide a simple interactive menu
def main():
    print("Swim in Rising Water — interactive runner")
    print("1) Run built-in examples & tests")
    print("2) Enter custom grid")
    print("3) Generate random grid and solve")
    print("4) Exit")
    choice = input("Choose option (1-4): ").strip()
    if choice == "1":
        run_examples_and_tests()
        return
    elif choice == "2":
        print("Enter grid row by row, values separated by spaces. Empty line to finish.")
        rows = []
        while True:
            line = input()
            if not line.strip():
                break
            row = [int(x) for x in line.split()]
            rows.append(row)
        if not rows:
            print("No grid entered.")
            return
        # Validate square
        n = len(rows)
        if any(len(r) != n for r in rows):
            print("Error: grid must be square (N x N).")
            return
        print("Your grid:")
        print_grid(rows)
        ans = swim_in_rising_water_dijkstra(rows)
        print("Minimum time to reach bottom-right (Dijkstra):", ans)
        return
    elif choice == "3":
        n = int(input("Enter N (grid size N x N): ").strip())
        seed_input = input("Optional random seed (press enter to skip): ").strip()
        seed = int(seed_input) if seed_input else None
        max_val_input = input("Optional maximum elevation (press enter for default): ").strip()
        max_val = int(max_val_input) if max_val_input else None
        grid = generate_random_grid(n, seed=seed, max_val=max_val)
        print("Generated grid:")
        print_grid(grid)
        ans = swim_in_rising_water_dijkstra(grid)
        print("Minimum time to reach bottom-right (Dijkstra):", ans)
        return
    elif choice == "4":
        print("Exiting.")
        return
    else:
        print("Invalid choice. Exiting.")
        return


# Allow importing functions without running the CLI
if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nInterrupted by user. Goodbye.")
