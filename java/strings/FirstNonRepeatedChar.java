import java.util.LinkedHashMap;
import java.util.Map;

/**
 * Problem: Find the First Non-Repeated Character in a String
 *
 * Given a string, the task is to find the first character that does not repeat.
 *
 * Approach:
 * 1. Use a LinkedHashMap to store the frequency of each character.
 *    - Key: Character
 *    - Value: Count of occurrences
 * 2. LinkedHashMap maintains the insertion order, unlike HashMap.
 *    This ensures we check characters in the order they appear.
 * 3. Iterate through the string and populate the map with counts.
 * 4. Iterate through the map entries:
 *    - The first character with a count of 1 is the answer.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * References:
 * - LeetCode: https://leetcode.com/problems/first-unique-character-in-a-string/description/
 * - GeeksforGeeks: https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
 */
public class FirstNonRepeatedChar {

    /**
     * Finds the first non-repeated character in the string.
     * Returns the character if found, or a message if not.
     *
     * @param str the input string
     * @return first non-repeated character as a String, or message if none found
     */
    public static String firstNonRepeated(String str) {
        if (str == null || str.isEmpty()) {
            return "Input string is null or empty";
        }

        LinkedHashMap<Character, Integer> charCountMap = new LinkedHashMap<>();

        // Count frequency of each character
        for (char ch : str.toCharArray()) {
            charCountMap.put(ch, charCountMap.getOrDefault(ch, 0) + 1);
        }

        // Find the first character with count 1
        for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
            if (entry.getValue() == 1) {
                return "First non-repeated character: " + entry.getKey();
            }
        }

        return "No non-repeated character found";
    }

    public static void main(String[] args) {
        // Diverse test cases
        String[] testStrings = {
            "swiss",        // w
            "hello",        // h
            "aabbcc",       // none
            "programming",  // p
            "",             // empty
            "x",            // x
            null,           // null
            "aabbcddee",    // c
            "aabbccddeeffg" // g
        };

        for (String s : testStrings) {
            System.out.println("Input: " + s);
            System.out.println("Output: " + firstNonRepeated(s));
            System.out.println("-------------------------");
        }
    }
}