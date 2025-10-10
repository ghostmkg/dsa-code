import ast

class Solution:
    def uniquePathsIII(self, grid):
        rows, cols = len(grid), len(grid[0])
        empty = 0
        start_x = start_y = -1

        # Find start and count empty cells
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    empty += 1
                elif grid[i][j] == 1:
                    start_x, start_y = i, j

        if start_x == -1:
            raise ValueError("Start cell (1) not found in grid.")

        path_count = [0]  # store total found paths by reference

        def dfs(x, y, remain, path):
            # Out of bounds or obstacle
            if not (0 <= x < rows and 0 <= y < cols) or grid[x][y] == -1:
                return 0

            # If reached end
            if grid[x][y] == 2:
                if remain == -1:
                    path_count[0] += 1
                    print(f"✅ Path {path_count[0]} found: {path + [(x, y)]}")
                    return 1
                else:
                    print(f"❌ Reached end too early at {x,y}, remain={remain}")
                    return 0

            # Mark visited
            temp = grid[x][y]
            grid[x][y] = -1
            path.append((x, y))
            print(f"➡️ Visiting {x,y}, remain={remain}")

            total = 0
            for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                total += dfs(x+dx, y+dy, remain-1, path)

            # Backtrack
            grid[x][y] = temp
            last = path.pop()
            print(f"🔙 Backtracking from {last}")

            return total

        total_paths = dfs(start_x, start_y, empty, [])
        print(f"\n🌟 Total valid paths: {total_paths}")
        return total_paths


def read_grid_choice():
    print("Choose input method:")
    print("1) Paste Python list-of-lists (e.g. [[1,0,0,0],[0,0,0,0],[0,0,2,-1]])")
    print("2) Enter rows and cols, then enter each row (space or comma separated numbers)")
    choice = input("Choice (1 or 2): ").strip()

    if choice == '1':
        print("Paste the grid now. End with an empty line and press 2 times enter:")
        lines = []
        while True:
            try:
                line = input()
            except EOFError:
                break
            if line.strip() == "":
                break
            lines.append(line)
        grid = ast.literal_eval(" ".join(lines))
        return grid

    elif choice == '2':
        r, c = map(int, input("Enter rows and cols: ").split())
        print(f"Enter {r} rows, each with {c} integers:")
        grid = []
        for i in range(r):
            row = list(map(int, input(f"Row {i+1}: ").replace(',', ' ').split()))
            grid.append(row)
        return grid
    else:
        raise ValueError("Invalid choice")


if __name__ == "__main__":
    grid = read_grid_choice()
    print("\nYour grid:")
    for row in grid:
        print(row)
    print()

    sol = Solution()
    sol.uniquePathsIII(grid)
