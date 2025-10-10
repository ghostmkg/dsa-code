public class ArrayPythagorasTriplet {

    public static void main(String[] args) {
        int[] arr = {3, 1, 4, 6, 5};
        System.out.println(isPythagorasTripletExists(arr) ? "TRUE" : "FALSE");
    }

    private static boolean isPythagorasTripletExists(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] * arr[i];
        }

        Arrays.sort(arr);

        for (int i = arr.length - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left <= right) {
                if (arr[left] + arr[right] == arr[i]) {
                    return true;
                } else if (arr[left] + arr[right] < arr[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }
}
