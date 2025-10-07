/*
 * 🔍 TwoDArraySearch.java
 *
 * [Algorithm]: Linear Search in a 2D Matrix
 * [Description]: Reads a matrix from user input and searches for a given key.
 * [Author]: Akriti Saroj (Hacktoberfest 2025)
 * [License]: MIT License
 * 
 * 👩‍💻 How to Run:
 *   1️⃣ Compile: javac TwoDArraySearch.java
 *   2️⃣ Run:     java TwoDArraySearch
 */

import java.util.*;

public class TwoDArraySearch {

    /**
     * Searches for a key in the given 2D matrix.
     *
     * @param matrix the 2D integer array
     * @param key    the value to search for
     * @return true if found, false otherwise
     */
    public static boolean search(int[][] matrix, int key) {
        if (matrix == null || matrix.length == 0) {
            System.out.println("⚠️ Matrix is empty!");
            return false;
        }

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == key) {
                    System.out.println("\n✅ Found " + key + " at cell: (" + i + ", " + j + ")");
                    return true;
                }
            }
        }
        System.out.println("\n❌ " + key + " not found in matrix.");
        return false;
    }

    /**
     * Reads and prints a matrix, then searches for a user-specified key.
     */
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.println("🔹 2D Array Search Program (Hacktoberfest 2025)\n");

        // Input matrix size
        System.out.print("Enter number of rows: ");
        int n = scn.nextInt();

        System.out.print("Enter number of columns: ");
        int m = scn.nextInt();

        int[][] matrix = new int[n][m];

        // Input matrix elements
        System.out.println("\n📥 Enter elements row by row:");
        for (int i = 0; i < n; i++) {
            System.out.print("Row " + (i + 1) + ": ");
            for (int j = 0; j < m; j++) {
                matrix[i][j] = scn.nextInt();
            }
        }

        // Print the matrix
        System.out.println("\n📋 Matrix is:");
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }

        // Input key to search
        System.out.print("\n🔍 Enter key to search: ");
        int key = scn.nextInt();

        // Perform search
        search(matrix, key);

        scn.close();
    }
}
