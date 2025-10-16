public class MergeSort{
    public static void main(String args[]){
        int arr[] = {6, 3, 9, 5, 2, 8};
        mergeSort(arr, 0, arr.length-1);
        printArr(arr);
        }

    public static void printArr(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.println(arr[i] + " ");
        }
        System.out.println();
    }

    public static void mergeSort(int arr[], int si, int ei){
        if(si >= ei){
            return;
        }
        int mid = si+(ei-si)/2;
        mergeSort(arr, si, mid);  //left part
        mergeSort(arr, mid+1, ei);  //right part
        merge(arr, si, mid, ei);    // merge function called after sorting

    }

    public static void merge(int arr[], int si, int mid, int ei){

        // left(0, 3) = 3-0+1 => 4 (bec we started from 0 idx)
        // right(4, 6) = 6-4+1 => 4
        int temp[] = new int[ei-si+1];
        int i = si;     // iterator for left part
        int j = mid+1;  // iterator for right part
        int k = 0;      // iterator for temp arr


        while(i <= mid && j <= ei){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }else{
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        // for leftover elements (if exists) of left side
        while(i <= mid){
            temp[k++] = arr[i++];
        }

        // for leftover elements (if exists) of right
        while(j <= ei){
            temp[k++] = arr[j++];
        }

        // copy temp to og array
        for(k=0, i=si; k<temp.length; k++, i++){
            arr[i] = temp[k];
        }
    }


}