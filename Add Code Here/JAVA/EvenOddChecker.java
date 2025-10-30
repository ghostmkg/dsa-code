/*
 * Program: Even or Odd Checker
 * Author: Akshat Patil
 * Date: October 27, 2025
 * Description: 
 * This program takes an integer input from the user
 * and checks whether it is even or odd using the modulus operator.
 */

import java.util.Scanner;

public class EvenOddChecker {
    public static void main(String[] args) {

        // Create Scanner object to take input from user
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt(); // Input from user

        // Check whether the number is even or odd
        if (number % 2 == 0) {
            System.out.println(number + " is an Even number.");
        } else {
            System.out.println(number + " is an Odd number.");
        }

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
