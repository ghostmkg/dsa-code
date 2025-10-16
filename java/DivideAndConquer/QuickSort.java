public class QuickSort{
    public static void main(String args[]){
        int arr[] = {6, 3, 9, 8, 2, 5};
        quickSort(arr, 0, arr.length-1);
        printArr(arr);
    }

    public static void printArr(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void quickSort(int arr[], int si, int ei){
        if(si >= ei){
            return;
        }

        // select a pivot (we take left here)
        
        // partitioning recursion
        int partitionIdx = partition(arr, si, ei);
        quickSort(arr, si, partitionIdx-1);     // left array
        quickSort(arr, partitionIdx+1, ei);     // right array
    }

    public static int partition(int arr[], int si, int ei){

        // we select the pivot as last element 
        int pivot = arr[ei];
        int i = si-1;           // makes space for elements smaller than pivot
        
        for(int j=si; j<ei; j++){
            if(pivot >= arr[j]){
                i++;
                // swap i and j
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
            }
        }

        // incremented i again for maiking space for pivot
        i++;
        int temp = pivot;
        arr[ei] = arr[i];
        arr[i] = temp;
        return i;
    }
}