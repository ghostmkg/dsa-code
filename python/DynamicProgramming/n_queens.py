def solve_n_queens(n):
    def is_safe(board, row, col):
        for i in range(col):
            if board[row][i] == 1:
                return False
        
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1
            
        i, j = row, col
        while i < n and j >= 0:
            if board[i][j] == 1:
                return False
            i += 1
            j -= 1
            
        return True

    def solve(board, col):
        if col >= n:
            return True
            
        for i in range(n):
            if is_safe(board, i, col):
                board[i][col] = 1
                if solve(board, col + 1):
                    solutions.append([row[:] for row in board])
                board[i][col] = 0
                
        return False

    solutions = []
    board = [[0 for x in range(n)] for y in range(n)]
    solve(board, 0)
    return solutions

def print_solution(board):
    for row in board:
        print(' '.join(['Q' if x == 1 else '.' for x in row]))
    print()


n = 4
solutions = solve_n_queens(n)
for i, solution in enumerate(solutions, 1):
    print(f"Solution {i}:")
    print_solution(solution)