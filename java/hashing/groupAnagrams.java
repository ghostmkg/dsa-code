/**
 * Author: Anshul Saxena
 * Program: Group Anagrams using HashMap (Optimized)
 * Description: Groups words that are anagrams of each other using character frequency hashing.
 * Time Complexity: O(n * k), where n = number of words, k = average word length
 * Space Complexity: O(n * k)
 */

import java.util.*;

public class GroupAnagramsHashing {

    public static List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length == 0) return Collections.emptyList();

        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            int[] freq = new int[26];
            for (char c : s.toCharArray()) freq[c - 'a']++;

            // Convert frequency array to unique string key, e.g. "a1b0c2..."
            StringBuilder keyBuilder = new StringBuilder();
            for (int f : freq) keyBuilder.append('#').append(f);
            String key = keyBuilder.toString();

            map.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(map.values());
    }

    public static void main(String[] args) {
        String[] input = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> result = groupAnagrams(input);

        System.out.println("Grouped Anagrams:");
        for (List<String> group : result) {
            System.out.println(group);
        }
    }
}
