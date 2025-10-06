import java.util.*;

public class TwoDArraySearch {

    public static boolean search(int matrix[][], int key) {
        for(int i=0; i<matrix.length; i++) {
            for(int j=0; j<matrix[0].length; j++) {
                if(matrix[i][j] == key) {
                    System.out.println();
                    System.out.println("Found " + key + " at the cell: (" + i + ", " + j + ")");
                    return true;
                }
            }
        }
        System.out.println("Not found");
        return false;
    }

    public static void main(String[] args) {
        int matrix[][] = new int[3][3];
        int n = matrix.length, m = matrix[0].length;

        Scanner scn = new Scanner(System.in);

        // input
        for(int i = 0; i < n; i++) {
            System.out.print("Enter row " + (i+1) + " (" + m + " numbers): ");
            for(int j = 0; j < m; j++) {
                matrix[i][j] = scn.nextInt();
            }
        }

        // output
        System.out.println("\nMatrix is:");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        scn.close();

        search(matrix, 5);
    }
}
