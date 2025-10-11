import java.util.*;
// saddle point is a element which is min in its row and max in its columns(one or no saddle point per matrix)
public class SaddlePoint{
    public static void main(String args []){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int [][] arr = new int[n][m];

        //Input for n*m
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = sc.nextInt();
            }
        }

        boolean found = false;
       for(int i=0;i<n;i++){
            int minr = minIndex(arr,i);

            if(max(arr,minr,i)){
                System.out.println("Saddle point: "+arr[i][minr]);
                found = true;
                break;
            }
       }
       if(!found)
       System.out.println("Invalid input");
    }
    public static int minIndex(int [][] arr, int row){
        int min = arr[row][0];
        int jmin=0;
        for(int j=0;j<arr[0].length;j++){
            if(arr[row][j]<min){
                min = arr[row][j];
                jmin = j;
            }
        }
        return jmin;
    }
    public static boolean max(int [][] arr,int min,int i){
        int max = arr[i][min];
        for(int r=0;r<arr.length;r++){
            if(arr[r][min]>max){
                return false;
            }
        }
        return true;
    }

}
