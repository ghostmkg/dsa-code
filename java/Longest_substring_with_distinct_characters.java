//  Problem: Longest Substring with Distinct Characters
//  Objective: Find the length of the longest substring without repeating characters.
//  Approach: Sliding Window + HashSet
//  Time Complexity: O(n)
//  Space Complexity: O(min(n, charset size))

import java.util.HashSet;

public class Longest_substring_with_distinct_characters {

    public static int longestUniqueSubstr(String s) {
        int start = 0, max = 0;
        HashSet<Character> set = new HashSet<>();

        for (int end = 0; end < s.length(); end++) {
            // If character already exists in the set, shrink the window from the left
            while (set.contains(s.charAt(end))) {
                set.remove(s.charAt(start));
                start++;
            }

            // Add current character to set
            set.add(s.charAt(end));

            // Update max length
            max = Math.max(max, end - start + 1);
        }
        return max;
    }

    //  Example Test
    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println("Length of longest substring: " + longestUniqueSubstr(s));
    }
}
