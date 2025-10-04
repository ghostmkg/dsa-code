// Given a string s that contains only digits (0-9) and an integer target, return all possible strings by inserting the binary operator ' + ', ' - ', and/or ' * ' between the digits of s such that the resultant expression evaluates to the target value.

// Note:

// Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine.
// It is allowed to not insert any of the operators.
// Driver code will print the final list of strings in lexicographically smallest order.
// Examples:

// Input: s = "124", target = 9
// Output: ["1+2*4"]
// Explanation: The valid expression that evaluate to 9 is 1 + 2 * 4
// Input: s = "125", target = 7
// Output: ["1*2+5", "12-5"]
// Explanation: The two valid expressions that evaluate to 7 are 1 * 2 + 5 and 12 - 5.
// Input: s = "12", target = 12
// Output: ["12"] 
// Explanation: s itself matches the target. No other expressions are possible.
// Input: s = "987612", target = 200
// Output: []
// Explanation: There are no expressions that can be created from "987612" to evaluate to 200.
// Constraints:
// 1 ≤ s.size() ≤ 9
// s consists of only digits (0-9).
// -231 ≤ target ≤ 231-1

/*
 * Problem: Generate all possible expressions by inserting +, -, * operators 
 *           between digits of a string such that the expression evaluates 
 *           to a given target value.
 *
 * Approach: Backtracking / DFS (Depth-First Search)
 *
 * Key idea:
 *  - We recursively try all possible placements of operators between digits.
 *  - Maintain running evaluation (`currVal`), previous operand (`prevOpr`), 
 *    and the current expression string.
 *  - Use backtracking to explore all combinations.
 *
 * Time Complexity: O(4^n) (in worst case, for each position we try 3 operators)
 * Space Complexity: O(n) (recursion stack depth)
 */

import java.util.*;

class Solution {

    /**
     * Recursive helper function to explore all possible expressions.
     *
     * @param s          The numeric string input.
     * @param target     The target value we want to achieve.
     * @param idx        Current index in the string.
     * @param currVal    Current evaluated result of the formed expression so far.
     * @param prevOpr    The last operand used (to handle multiplication precedence).
     * @param expression Current expression string being built.
     * @param result     List to store valid expressions that match the target.
     */
    public void solve(String s, int target, int idx, long currVal, long prevOpr, String expression, ArrayList<String> result) {
        // Base Case: If we've reached the end of the string
        if (idx == s.length()) {
            // If the current expression evaluates to the target, add it to the result
            if (currVal == target) {
                result.add(expression);
            }
            return;
        }

        // Try all possible partitions of the remaining string
        for (int i = idx; i < s.length(); i++) {

            // Skip invalid numbers with leading zeros (e.g., "05", "00")
            if (i > idx && s.charAt(idx) == '0') {
                break;
            }

            // Extract current number from substring
            long currNum = Long.parseLong(s.substring(idx, i + 1));

            // Case 1: First number (no operator needed before it)
            if (idx == 0) {
                // Start the expression with the first number
                solve(s, target, i + 1, currNum, currNum, expression + currNum, result);
            } else {
                // Case 2: Addition
                solve(s, target, i + 1, currVal + currNum, currNum, expression + "+" + currNum, result);

                // Case 3: Subtraction
                solve(s, target, i + 1, currVal - currNum, -currNum, expression + "-" + currNum, result);

                // Case 4: Multiplication
                // To handle operator precedence, adjust current value:
                // Remove the effect of previous operand and multiply it with current number.
                long newVal = currVal - prevOpr + (prevOpr * currNum);
                solve(s, target, i + 1, newVal, prevOpr * currNum, expression + "*" + currNum, result);
            }
        }
    }

    /**
     * Public method to initiate the recursive expression generation.
     *
     * @param s      The input string of digits.
     * @param target The target value to achieve.
     * @return       A list of all valid expressions that evaluate to the target.
     */
    public ArrayList<String> findExpr(String s, int target) {
        ArrayList<String> result = new ArrayList<>();
        solve(s, target, 0, 0, 0, "", result);
        return result;
    }
}
