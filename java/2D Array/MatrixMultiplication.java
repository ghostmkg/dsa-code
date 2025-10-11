import java.util.*;

public class MatrixMultiplication {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.err.println("First Matrix Dimensions and Elements:");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();

        int [][] arr1 = new int[r1][c1];

        //Input for n*m
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                arr1[i][j] = sc.nextInt();
            }
        }

        System.err.println("Second Matrix Dimensions and Elements:");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();

        // Validation (1st col == 2nd row)
        if(c1!=r2){
            System.out.println("Invalid Dimensions");
            System.exit(1);
        }

        int [][] arr2 = new int[r2][c2];

        //Input for a*b
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                arr2[i][j] = sc.nextInt();
            }
        }

        int [][] res = new int[r1][c2];

        for(int i=0;i<res.length;i++){
            for(int j=0;j<res[0].length;j++){
                for(int k=0;k<c1;k++){ //k runs till common dimension part
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        System.out.println("Resultant Matrix:");
        for(int i=0;i<res.length;i++){
            for(int j=0;j<res[0].length;j++){
               System.out.print(res[i][j]+" ");
            }
            System.out.println();
        }
    }
}

