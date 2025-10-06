import java.util.Scanner;

public class primenum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        sc.close();

        if (isPrime(n)) {
            System.out.println(n + " is a Prime number.");
        } else {
            System.out.println(n + " is NOT a Prime number.");
        }
    }

    static boolean isPrime(int n) {
        if (n <= 1) return false;     // 0 and 1 are not prime
        if (n == 2 || n == 3) return true;  // 2 and 3 are prime
        if (n % 2 == 0) return false; // eliminate even numbers

        int limit = (int) Math.sqrt(n); // check up to √n
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
