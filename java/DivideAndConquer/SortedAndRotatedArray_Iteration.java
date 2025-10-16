public class SortedAndRotatedArray_Iteration{
    public static void main(String args[]){
        int arr[] = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        System.out.println(search(arr, target, 0, arr.length-1));

    }

    public static int search(int arr[], int target,int si,int ei){
        
        while(si<=ei){
            int mid = si+(ei-si)/2;
            // case 1: sabse basic case
            if(target == arr[mid]){
                return mid;
            }

            // case2: if target is less than mid (Lies on Line1)
            if(arr[si] <= arr[mid]){
                if(target >= arr[si] && target <= arr[mid]){
                    ei = mid-1;
                }else{
                    si = mid+1;
                }
            }
            else{       // case 3:  if(arr[mid] <= arr[ei])
                if(target >= arr[mid] && target <= arr[ei]){
                    si = mid+1;
                }else{
                    ei = mid-1;
                }
            }
        }
        return -1;
    }
}