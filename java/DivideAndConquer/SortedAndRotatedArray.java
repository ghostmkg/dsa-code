public class SortedAndRotatedArray{
    public static void main(String args[]){

        int arr[] = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;   // output should be idx of target(4)
        int targetIdx = search(arr, target, 0, arr.length-1);
        System.out.println(targetIdx);
    }

    public static int search(int arr[], int target, int si, int ei){

        // base case
        if(si > ei){
             return -1;
        }

        // sabse pehle mid nikal lete hai
        int mid = si+(ei-si)/2;

        // sabse basic case
        if(target == arr[mid]){
            return mid;
        }

        // case 2: mid may lie of Line1
        if(arr[si] <= arr[mid]){

            // case a:
            if(target >= arr[si] && target <= arr[mid]){
                return search(arr, target, si, mid-1);
            }else{      // case b:
                return search(arr, target, mid+1, ei);
            }
        }

        else{           // arr[mid] <= arr[ei]

            // case a: 
            if(target >= arr[mid] && target <= arr[ei]){
                return search(arr, target, mid+1, ei);
            }else{      // case b:
                return search(arr, target, si, mid-1);
            }

        }

    }
}