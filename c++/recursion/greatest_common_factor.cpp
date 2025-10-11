/*
    Problem: Find Greatest Common Factor (GCF)
    -------------------------------------------
    Given two integers x and y, find their Greatest Common Factor (also known as GCD).

    The GCF of two numbers is the largest integer that divides both without leaving a remainder.

    ---------------------------------------------------------
    🧠 Approach (Euclidean Algorithm):
    - If y > x, swap the numbers so x ≥ y.
    - Base Case: If y == 0, return x.
    - Recursive Step: gcf(x, y) = gcf(y, x % y)

    This approach is based on the property:
        gcd(a, b) = gcd(b, a % b)

    ---------------------------------------------------------
    🧮 Example:
        Input: x = 20, y = 28
        Output: 4

    ---------------------------------------------------------
    ⏱️ Time Complexity: O(log(min(x, y)))
    🧮 Space Complexity: O(log(min(x, y))) due to recursion
*/

#include <iostream>
using namespace std;

// Recursive function to compute GCF using Euclidean algorithm
int gcf(int x, int y) {
    if (y > x)
        return gcf(y, x);  // Ensure x >= y
    if (y == 0)
        return x;
    return gcf(y, x % y);
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Greatest Common Factor: " << gcf(x, y) << "\n";
    return 0;
}
