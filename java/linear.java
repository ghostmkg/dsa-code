public class linear {
    public static int LinearSearch(int arr[], int key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16 };
        int key = 10;
        int index = LinearSearch(arr, key);
        if (index == -1) {
            System.out.println("Not found");
        } else {
            System.out.println("Key is at index: " + index);
        }
    }

}
