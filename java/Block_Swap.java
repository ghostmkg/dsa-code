2import java.util.Scanner;

public class Block_Swap {
    public static void printArray(int[] arr){
        System.out.print("Array after Block Swapping: ");
        for(int i = 0; i < arr.length; i++){
            if(arr.length - 1 == i){
                System.out.print(arr[i]);
            }else{
                System.out.print(arr[i] + ", ");
            }
        }
    }
    public static void leftRotate(int[] arr, int n, int d){
        if(d == 0 || d == n){
            return;
        }
        if(d > n){
            d %= n;
        }
        int i = d;
        int j = n - d;
        while (i != j) {
            if(i < j){
                swap(arr, d - i, d + j - i, i);
                j -= i;
            }else{
                swap(arr, d - i, d, j);
                i -= j;
            }
        }
        swap(arr, d - i, d, i);
    }
    public static void swap(int[] arr, int fi, int si, int d){
        int temp;
        for(int i = 0; i < d; i++){
            temp = arr[fi + i];
            arr[fi + i] = arr[si + i];
            arr[si + i] = temp;
        }
    }
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        System.out.print("Enter the Block size: ");
        int d = sc.nextInt();

        int array[] = new int[n];

        System.out.print("Enter the numbers in the array: ");
        for(int i = 0; i < n; i++){
            array[i] = sc.nextInt();
        }

        leftRotate(array, n, d);
        printArray(array);

        sc.close();
    }
}