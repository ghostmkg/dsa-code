# Question:
# The n-rooknight puzzle is the problem of placing n rooknights on an n x n chessboard such that no two rooknights attack each other.

# Given an integer n, return all distinct solutions to the n-rooknight puzzle. You may return the answer in any order.

# Each solution contains a distinct board configuration of the n-rooknight placement, where 'R' and '.' both indicate a rooknight and an empty space, respectively.

# Note:

# The Rooknight’s movement (from position (x, y)):
# Rook movement:

# Any square of the form (x ± k, y) or (x, y ± k), where k is any positive integer.

# Knight movement:

# Exactly one of the following eight jumps:

# (x + 2, y + 1)  (x + 2, y – 1)

# (x – 2, y + 1)  (x – 2, y – 1)

# (x + 1, y + 2)  (x + 1, y – 2)

# (x – 1, y + 2)  (x – 1, y – 2)

# Input
# User Task
# As this is a functional problem, Your task here is to implement the function solveNrooknight, which takes only an integer n as its argument, representing the size of the chessboard.


# Custom Input
# The first line of the input contains a single integer n, representing the dimensions of the chessboard.
# Output
# Return an array of array of strings representing all the possible ways to place the n Rooknight on the chessboard so that no two rooknight attack each other.

# Custom Output
# Print the whole combinations of n x n chess board, where Rooknight are placed without attacking each other, where combinations are separated via new line.
# Constraints
# 1 ≤ n ≤ 7
# Example
# Sample Input
# 3
# Sample Output
# R..
# .R.
# ..R

# ..R
# .R.
# R..
# Explanation:
# There exist two distinct solutions to the 2 rooknight puzzle as shown above

# Solution:

def solveNrooknight(n):
    board = [["." for _ in range(n)] for _ in range(n)]
    result = []

    moves = [(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]

    def isSafe(row, col):
        # Check Rooknight in the same row
        for i in range(n):
            if board[row][i] == "R":
                return False

        # Check Rooknight in the same column
        for i in range(n):
            if board[i][col] == "R":
                return False

        for dr, dc in moves:
            nr, nc = row + dr, col + dc 
            if 0 <= nr < n and 0 <= nc < n and board[nr][nc] == "R":
                return False  

        return True 

    def backtrack(row):
        if row == n:
            result.append(["".join(r) for r in board])
            return
        for col in range(n):
            if isSafe(row, col):
                board[row][col] = "R"    
                backtrack(row + 1)       
                board[row][col] = "."    

    backtrack(0) 
    return result