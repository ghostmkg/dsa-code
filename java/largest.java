import java.util.*;

public class largest {
    public static int getLargest(int num[]) {
        int lar = Integer.MIN_VALUE;
        for (int i = 0; i < num.length; i++) {
            if (lar < num[i]) {
                lar = num[i];
            }
        }
        return lar;
    }

    public static void main(String[] args) {
        int num[] = { 1, 2, 6, 3, 5 };
        System.out.println("Largest number is: " + getLargest(num));
    }
}