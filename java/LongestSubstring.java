import java.util.HashMap;
import java.util.Map;

/**
 * A solution for finding the length of the longest substring without repeating characters.
 *
 * This implementation uses the "sliding window" technique with a HashMap.
 * The "window" is a substring (represented by a left and right pointer) that we try to expand.
 *
 * - We use a HashMap to store the most recent index of each character we've seen.
 * - We expand the window by moving the right pointer.
 * - If we find a repeating character, we shrink the window by moving the left pointer
 * to the right of the last occurrence of that character.
 */
public class LongestSubstring {

    /**
     * Calculates the length of the longest substring without repeating characters.
     * @param s The input string.
     * @return The length of the longest substring.
     */
    public int lengthOfLongestSubstring(String s) {
        // Handle edge case of an empty or null string.
        if (s == null || s.length() == 0) {
            return 0;
        }

        // A map to store the last seen index of each character.
        // Key: character, Value: index
        Map<Character, Integer> map = new HashMap<>();
        
        int maxLength = 0;
        int left = 0; // The left pointer of our sliding window.

        // Iterate through the string with the right pointer.
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            // If the current character is already in our window (i.e., its last seen
            // index is within the current window defined by `left`),
            // we must shrink the window by moving the `left` pointer.
            if (map.containsKey(currentChar)) {
                // Move the left pointer to the right of the last occurrence of the character.
                // We use Math.max to ensure the left pointer never moves backward.
                left = Math.max(left, map.get(currentChar) + 1);
            }

            // Update the last seen index of the current character.
            map.put(currentChar, right);

            // The length of the current window is `right - left + 1`.
            // Update our maxLength if the current window is longer.
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    // Main method to demonstrate usage.
    public static void main(String[] args) {
        LongestSubstring solution = new LongestSubstring();
        
        String s1 = "abcabcbb";
        System.out.println("Input: \"" + s1 + "\"");
        System.out.println("Output: " + solution.lengthOfLongestSubstring(s1)); // Expected: 3

        System.out.println("\nInput: \"bbbbb\"");
        String s2 = "bbbbb";
        System.out.println("Output: " + solution.lengthOfLongestSubstring(s2)); // Expected: 1

        System.out.println("\nInput: \"pwwkew\"");
        String s3 = "pwwkew";
        System.out.println("Output: " + solution.lengthOfLongestSubstring(s3)); // Expected: 3

        System.out.println("\nInput: \"\"");
        String s4 = "";
        System.out.println("Output: " + solution.lengthOfLongestSubstring(s4)); // Expected: 0

        System.out.println("\nInput: \"dvdf\"");
        String s5 = "dvdf";
        System.out.println("Output: " + solution.lengthOfLongestSubstring(s5)); // Expected: 3
    }
}