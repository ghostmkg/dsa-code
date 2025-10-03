import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read number of elements
        int n = sc.nextInt();

        // Create an ArrayList of Integers
        ArrayList<Integer> numbers = new ArrayList<>();

        // Read n integers and add them to the ArrayList
        for (int i = 0; i < n; i++) {
            numbers.add(sc.nextInt());
        }

        // Sort the ArrayList in ascending order using bubble sort
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = 0; j < numbers.size() - i - 1; j++) {
                if (numbers.get(j) > numbers.get(j + 1)) {
                    // Swap numbers[j] and numbers[j+1]
                    int temp = numbers.get(j);
                    numbers.set(j, numbers.get(j + 1));
                    numbers.set(j + 1, temp);
                }
            }
        }

        // Print the sorted ArrayList
        for (int num : numbers) {
            System.out.print(num + " ");
        }
    }
}
