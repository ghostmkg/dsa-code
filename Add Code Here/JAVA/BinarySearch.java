// Program: Binary Search in Java
// Purpose: To find whether a given number exists in a sorted array using Binary Search technique

import java.util.Scanner; // Import Scanner class for user input

public class Binary_Search
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input

        int i = 0, flag = 0; // 'flag' variable will be used to indicate if element is found or not

        // Step 1: Initialize a sorted array (Binary Search works only on sorted arrays)
        int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        
        // Step 2: Display the array elements
        System.out.println("Array elements are:");
        for(i = 0; i < 10; i++)
        {
            System.out.println(a[i]);
        }
        
        // Step 3: Ask the user to enter the number to search
        System.out.println("Enter a number to search:");
        int num = sc.nextInt();
        
        // Step 4: Initialize variables for binary search
        int f = 0;   // 'f' represents the first index
        int l = 9;   // 'l' represents the last index
        int m = 0;   // 'm' represents the middle index

        // Step 5: Perform Binary Search using while loop
        while(f <= l)
        {
            m = (f + l) / 2; // Calculate middle index

            // Case 1: Element found at mid position
            if(num == a[m])
            {
                flag = 1; // Mark flag as found
                break;    // Exit loop
            }

            // Case 2: If element is smaller than middle value, search in left half
            else if(num < a[m])
            {
                l = m - 1;
            }

            // Case 3: If element is greater than middle value, search in right half
            else
            {
                f = m + 1;
            }
        }

        // Step 6: Display result based on flag value
        if(flag == 0)
        {
            System.out.println("Search element not found");
        }
        else
        {
            System.out.println("Search element found at cell number " + (m + 1));
        }

        sc.close(); // Close Scanner object to prevent memory leak
    }
}
