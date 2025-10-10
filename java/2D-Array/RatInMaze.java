public class RatInMaze {
    /**
     * Utility function to check whether (x, y) is a valid move in the maze.
     */
    static boolean isSafe(int maze[][], int x, int y) {
        int rows = maze.length;
        int cols = maze[0].length;
        return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1);
    }
    /**
     * Solves the maze for variable-size input.
     */
    static boolean solveMaze(int maze[][]) {
        int rows = maze.length;
        int cols = maze[0].length;
        int sol[][] = new int[rows][cols];

        if (!solveMazeUtil(maze, 0, 0, sol)) {
            System.out.println("No solution exists");
            return false;
        }

        printSolution(sol);
        return true;
    }
    /**
     * A recursive utility to solve the maze problem.
     */
    static boolean solveMazeUtil(int maze[][], int x, int y, int sol[][]) {
        int rows = maze.length;
        int cols = maze[0].length;
        // Base case: destination is reached
        if (x == rows - 1 && y == cols - 1 && maze[x][y] == 1) {
            sol[x][y] = 1;
            return true;
        }
        // Check if maze[x][y] is valid
        if (isSafe(maze, x, y)) {
            sol[x][y] = 1; // mark x, y as part of the solution path
            // Try all possible moves: down, right, up, left
            if (solveMazeUtil(maze, x + 1, y, sol)) return true;
            if (solveMazeUtil(maze, x, y + 1, sol)) return true;
            if (solveMazeUtil(maze, x - 1, y, sol)) return true;
            if (solveMazeUtil(maze, x, y - 1, sol)) return true;
            // None moves are valid, BACKTRACK
            sol[x][y] = 0;
            return false;
        }
        return false;
    }
    /**
     * Utility function to print the solution matrix.
     */
    static void printSolution(int sol[][]) {
        System.out.println("Solution Path (1s):");
        for (int i = 0; i < sol.length; i++) {
            for (int j = 0; j < sol[0].length; j++) {
                System.out.print(sol[i][j] + " ");
            }
            System.out.println();
        }
    }
    /**
     * Usage Example: Try with any maze size!
     */
    public static void main(String args[]) {
        // Example: a 4x6 maze
        int maze[][] = {
            {1, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 1},
            {0, 1, 1, 1, 0, 0},
            {1, 0, 0, 1, 1, 1}
        };
        solveMaze(maze);
    }
}
