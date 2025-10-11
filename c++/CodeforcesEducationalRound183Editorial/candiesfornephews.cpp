/*  Problem Statment

                           A. Candies for Nephews
                        time limit per test1 second
                    memory limit per test256 megabytes
Monocarp has three nephews. New Year is coming, and Monocarp has 𝑛
 candies that he will gift to his nephews.

To ensure that none of the nephews feels left out, Monokarp wants to give each of the three nephews the same number of candies.

Determine the minimum number of candies that Monocarp needs to buy additionally so that he can give each of the three nephews the same number of candies. Note that all 𝑛
 candies that Monocarp initially has will be given to the nephews.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

Each test case consists of one line containing one integer 𝑛
 (1≤𝑛≤100
) — the number of candies that Monocarp initially has.

Output
For each test case, print one integer — the minimum number of candies that Monokarp needs to buy additionally so that he can give each of the three nephews the same number of candies.
*/

// 🧠 Approach:
//     - If n is already divisible by 3 → extra = 0
//     - Otherwise → find remainder r = n % 3
//       -> We need (3 - r) more candies to make it divisible by 3.

//       For example:
//         n = 8 → 8 % 3 = 2 → needs 1 more → 9 candies total.
//         n = 10 → 10 % 3 = 1 → needs 2 more → 12 candies total.

//     ---------------------------------------------------------
//     ⏱️ Time Complexity: O(1) per test case
//     🧮 Space Complexity: O(1)
// */



//SOLUTION
#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Find remainder when divided by 3
    int remainder = n % 3;

    // If already divisible, no extra candies needed
    if (remainder == 0)
        cout << 0 << '\n';
    else
        cout << 3 - remainder << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}