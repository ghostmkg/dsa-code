import java.util.Stack;

public class NextGreaterElement {

    static void printNextGreaterElements(int[] arr) {
        Stack stack = new Stack(); // using raw Stack for compatibility
        int[] result = new int[arr.length];

        // Traverse from right to left
        for (int i = arr.length - 1; i >= 0; i--) {
            // Pop smaller elements from stack
            while (!stack.isEmpty() && (int) stack.peek() <= arr[i]) {
                stack.pop();
            }

            // If stack is empty → no greater element
            if (stack.isEmpty()) {
                result[i] = -1;
            } else {
                result[i] = (int) stack.peek();
            }

            // Push current element into stack
            stack.push(arr[i]);
        }

        System.out.println("Element : Next Greater Element");
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i] + " --> " + result[i]);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 2, 25, 7, 8 };
        printNextGreaterElements(arr);
    }
}
