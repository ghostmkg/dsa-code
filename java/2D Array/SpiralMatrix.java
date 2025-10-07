/*
 * 🌀 SpiralMatrix.java
 *
 * [Algorithm]: Spiral Order Traversal of a Matrix
 * [Description]: Prints the elements of a 2D matrix in spiral (clockwise) order.
 * [Author]: Akriti Saroj (Hacktoberfest 2025)
 * [License]: MIT License
 * 
 * 👩‍💻 How to Run:
 *   1️⃣ Compile: javac SpiralMatrix.java
 *   2️⃣ Run:     java SpiralMatrix
 */

import java.util.*;

public class SpiralMatrix {

    /**
     * Prints the matrix elements in spiral order.
     *
     * @param matrix the 2D array to be printed in spiral order
     */
    public static void printSpiral(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            System.out.println("Matrix is empty!");
            return;
        }

        int startRow = 0, startCol = 0;
        int endRow = matrix.length - 1;
        int endCol = matrix[0].length - 1;

        System.out.println("\n🔹 Spiral Order Traversal:");

        while (startRow <= endRow && startCol <= endCol) {

            // → top row
            for (int j = startCol; j <= endCol; j++) {
                System.out.print(matrix[startRow][j] + " ");
            }

            // ↓ right column
            for (int i = startRow + 1; i <= endRow; i++) {
                System.out.print(matrix[i][endCol] + " ");
            }

            // ← bottom row
            if (startRow < endRow) {
                for (int j = endCol - 1; j >= startCol; j--) {
                    System.out.print(matrix[endRow][j] + " ");
                }
            }

            // ↑ left column
            if (startCol < endCol) {
                for (int i = endRow - 1; i > startRow; i--) {
                    System.out.print(matrix[i][startCol] + " ");
                }
            }

            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        System.out.println();
    }

    /**
     * Returns the matrix elements in spiral order as a list (for algorithmic use).
     *
     * @param matrix the 2D array
     * @return list of integers in spiral order
     */
    public static List<Integer> getSpiralList(int[][] matrix) {
        List<Integer> result = new ArrayList<>();

        if (matrix == null || matrix.length == 0) return result;

        int startRow = 0, startCol = 0;
        int endRow = matrix.length - 1;
        int endCol = matrix[0].length - 1;

        while (startRow <= endRow && startCol <= endCol) {
            for (int j = startCol; j <= endCol; j++) result.add(matrix[startRow][j]);
            for (int i = startRow + 1; i <= endRow; i++) result.add(matrix[i][endCol]);
            if (startRow < endRow)
                for (int j = endCol - 1; j >= startCol; j--) result.add(matrix[endRow][j]);
            if (startCol < endCol)
                for (int i = endRow - 1; i > startRow; i--) result.add(matrix[i][startCol]);

            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9, 10, 11, 12},
            {13,14, 15,16}
        };

        // Print formatted matrix
        System.out.println("📋 Original Matrix:");
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }

        // Print spiral traversal
        printSpiral(matrix);

        // Get spiral as a list (for testing or algorithmic reuse)
        List<Integer> spiral = getSpiralList(matrix);
        System.out.println("\n📜 Spiral List: " + spiral);
    }
}
