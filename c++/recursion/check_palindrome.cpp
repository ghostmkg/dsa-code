/*
    Problem: Check Palindrome (Recursive Approach)
    ----------------------------------------------
    Given an integer `n`, determine whether it is a palindrome.

    A number is a palindrome if it reads the same forward and backward.

    Example:
        Input: 121
        Output: Number is a palindrome

        Input: 123
        Output: Number is not a palindrome

    ---------------------------------------------------------
    🧠 Approach:
    - Use recursion to reverse the number.
    - Compare the reversed number with the original.

    ---------------------------------------------------------
    ⏱️ Time Complexity: O(d), where d = number of digits
    🧮 Space Complexity: O(d) for recursion stack
*/

#include <iostream>
using namespace std;

// Recursive function to reverse a number
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNumber(n / 10, rev * 10 + (n % 10));
}

// Function to check if number is palindrome
void checkPalindrome(int n) {
    if (n < 0) {
        cout << "Negative numbers are not considered palindromes.\n";
        return;
    }

    int reversed = reverseNumber(n);
    if (reversed == n)
        cout << "Number is a palindrome\n";
    else
        cout << "Number is not a palindrome\n";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    checkPalindrome(n);
    return 0;
}
