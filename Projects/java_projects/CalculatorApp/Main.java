package CalculatorApp;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        Scanner sc = new Scanner(System.in);
        int choice;
        double a, b;

        System.out.println("=== Simple Calculator ===");
        do {
            System.out.println("\n1. Add");
            System.out.println("2. Subtract");
            System.out.println("3. Multiply");
            System.out.println("4. Divide");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if (choice >= 1 && choice <= 4) {
                System.out.print("Enter first number: ");
                a = sc.nextDouble();
                System.out.print("Enter second number: ");
                b = sc.nextDouble();

                switch (choice) {
                    case 1:
                        System.out.println("Result: " + calc.add(a, b));
                        break;
                    case 2:
                        System.out.println("Result: " + calc.subtract(a, b));
                        break;
                    case 3:
                        System.out.println("Result: " + calc.multiply(a, b));
                        break;
                    case 4:
                        System.out.println("Result: " + calc.divide(a, b));
                        break;
                }
            } else if (choice != 5) {
                System.out.println("Invalid choice! Try again.");
            }
        } while (choice != 5);

        System.out.println("Exiting Calculator. Goodbye!");
        sc.close();
    }
}
