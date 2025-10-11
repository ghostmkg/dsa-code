def generateMatrix(n):
    """
    Generate an n x n matrix filled with elements from 1 to n² in spiral order.
    
    Args:
        n: Size of the matrix (n x n)
    
    Returns:
        List[List[int]]: The generated spiral matrix
    """
    # Initialize matrix with zeros
    matrix = [[0] * n for _ in range(n)]
    
    # Define boundaries
    top, bottom = 0, n - 1
    left, right = 0, n - 1
    
    num = 1  # Start filling from 1
    
    while top <= bottom and left <= right:
        # Fill top row from left to right
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1
        
        # Fill right column from top to bottom
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1
        
        # Fill bottom row from right to left (if still within bounds)
        if top <= bottom:
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1
        
        # Fill left column from bottom to top (if still within bounds)
        if left <= right:
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
    
    return matrix

# Alternative more concise solution
def generateMatrix_concise(n):
    matrix = [[0] * n for _ in range(n)]
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
    row, col, direction = 0, 0, 0
    
    for num in range(1, n * n + 1):
        matrix[row][col] = num
        
        # Calculate next position
        next_row = row + directions[direction][0]
        next_col = col + directions[direction][1]
        
        # If next position is invalid or already filled, change direction
        if (next_row < 0 or next_row >= n or 
            next_col < 0 or next_col >= n or 
            matrix[next_row][next_col] != 0):
            direction = (direction + 1) % 4
            next_row = row + directions[direction][0]
            next_col = col + directions[direction][1]
        
        row, col = next_row, next_col
    
    return matrix