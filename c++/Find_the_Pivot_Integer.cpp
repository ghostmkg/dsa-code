Question: –
Problem — Find the Pivot Integer

Given a positive integer n, find the pivot integer x such that:

1
+
2
+
.
.
.
+
𝑥
=
𝑥
+
(
𝑥
+
1
)
+
.
.
.
+
𝑛
1+2+...+x=x+(x+1)+...+n

If no such integer exists, return -1.

Example 1:

Input:
n = 8
Output:
6

Explanation:
The sum of numbers from 1 to 6 is equal to the sum from 6 to 8.

1
+
2
+
3
+
4
+
5
+
6
=
6
+
7
+
8
=
21
1+2+3+4+5+6=6+7+8=21
Example 2:

Input:
n = 1
Output:
1

Explanation:
Both sides equal 1 since there’s only one number.

Example 3:

Input:
n = 4
Output:
-1

Explanation:
No such integer exists because sums are unequal for all possible x.

Constraints:
1 <= n <= 1000

Intuition

We are looking for a point x that splits the range [1…n] into two parts having equal sums.

The total sum of numbers from 1 to n is:

𝑡
𝑜
𝑡
𝑎
𝑙
=
𝑛
(
𝑛
+
1
)
2
total=
2
n(n+1)
	​


If we choose some pivot x, then:

Left sum = sum from 1 to x = 
𝑥
(
𝑥
+
1
)
2
2
x(x+1)
	​


Right sum = total - sum from 1 to (x - 1) = total - 
(
𝑥
−
1
)
𝑥
2
2
(x−1)x
	​


We need to find x such that:

𝑥
(
𝑥
+
1
)
2
=
𝑡
𝑜
𝑡
𝑎
𝑙
−
(
𝑥
−
1
)
𝑥
2
2
x(x+1)
	​

=total−
2
(x−1)x
	​


Simplifying gives a clean check condition for each x.

Approach

Compute the total sum = n * (n + 1) / 2.

Loop through each possible pivot x from 1 to n.

For each x:

Compute left sum = x * (x + 1) / 2.

Compute right sum = total - (x * (x - 1) / 2).

If they are equal, return x.

If none matches, return -1.

Complexity

Time Complexity: O(n)
(one loop through all possible pivots)

Space Complexity: O(1)
(constant variables used)

Code : -
class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;

        for (int x = 1; x <= n; x++) {
            int leftSum = x * (x + 1) / 2;
            int rightSum = total - (x - 1) * x / 2;

            if (leftSum == rightSum)
                return x;
        }

        return -1;
    }
};

✅ Example Walkthrough

Input: n = 8

total = 36

Try x = 6 →
leftSum = 21, rightSum = 21 → ✅ Match → return 6.
