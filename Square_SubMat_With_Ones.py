from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        # Get number of rows and columns
        r = len(matrix)
        c = len(matrix[0])

        # dp[i][j] will store the size of the largest square 
        # whose bottom-right corner is at cell (i, j)
        dp = [[0] * c for _ in range(r)]

        count = 0  # To store total number of square submatrices

        # Initialize first row
        # Each 1 in the first row forms a 1x1 square
        for j in range(c):
            if matrix[0][j] == 1:
                dp[0][j] = 1
                count += 1
        
        # Initialize first column
        # Each 1 in the first column forms a 1x1 square
        for i in range(1, r):
            if matrix[i][0] == 1:
                dp[i][0] = 1
                count += 1

        # Fill the dp table for the rest of the matrix
        for i in range(1, r):
            for j in range(1, c):
                # If the cell is 0, no square can end here
                if matrix[i][j] == 0:
                    continue
                # If the cell is 1, find the smallest neighboring square
                # and extend it by 1 to form a bigger square
                elif dp[i-1][j] == 0 or dp[i-1][j-1] == 0 or dp[i][j-1] == 0:
                    dp[i][j] = 1  # Only a 1x1 square possible
                else:
                    # Minimum of top, left, and top-left + 1
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
                
                # Add the number of squares ending at (i, j)
                count += dp[i][j]
        
        # Return total count of all square submatrices with all 1s
        return count
