import heapq
from typing import List, Tuple, Optional

def heuristic(a: Tuple[int, int], b: Tuple[int, int]) -> int:
    """Manhattan distance heuristic"""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def astar(grid: List[List[int]], 
          start: Tuple[int, int], 
          goal: Tuple[int, int]) -> Optional[List[Tuple[int, int]]]:
    """
    A* pathfinding algorithm
    
    Args:
        grid: 2D grid where 0 is walkable, 1 is wall
        start: Starting position (row, col)
        goal: Goal position (row, col)
    
    Returns:
        List of positions forming the path, or None if no path exists
    """
    rows, cols = len(grid), len(grid[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    # Priority queue: (f_score, g_score, position)
    open_set = [(heuristic(start, goal), 0, start)]
    came_from = {}
    g_score = {start: 0}
    
    while open_set:
        _, curr_g, curr = heapq.heappop(open_set)
        
        if curr == goal:
            # Reconstruct path
            path = [goal]
            while path[-1] in came_from:
                path.append(came_from[path[-1]])
            return path[::-1]
        
        # Skip if we've found a better path already
        if curr_g > g_score.get(curr, float('inf')):
            continue
        
        for dx, dy in directions:
            neighbor = (curr[0] + dx, curr[1] + dy)
            
            # Check bounds and walls
            if (0 <= neighbor[0] < rows and 
                0 <= neighbor[1] < cols and 
                grid[neighbor[0]][neighbor[1]] == 0):
                
                tentative_g = curr_g + 1
                
                if tentative_g < g_score.get(neighbor, float('inf')):
                    came_from[neighbor] = curr
                    g_score[neighbor] = tentative_g
                    f_score = tentative_g + heuristic(neighbor, goal)
                    heapq.heappush(open_set, (f_score, tentative_g, neighbor))
    
    return None

def print_grid_with_path(grid: List[List[int]], path: List[Tuple[int, int]]):
    """Visualize the grid with the path"""
    path_set = set(path)
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if (i, j) in path_set:
                if (i, j) == path[0]:
                    print("S", end=" ")
                elif (i, j) == path[-1]:
                    print("G", end=" ")
                else:
                    print("*", end=" ")
            elif cell == 1:
                print("█", end=" ")
            else:
                print("·", end=" ")
        print()

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    
    start = (0, 0)
    goal = (4, 4)
    
    path = astar(grid, start, goal)
    
    if path:
        print("Path found:")
        for pos in path:
            print(f"({pos[0]},{pos[1]})", end=" ")
        print(f"\nSteps: {len(path) - 1}\n")
        
        print("Grid visualization:")
        print_grid_with_path(grid, path)
    else:
        print("No path found")