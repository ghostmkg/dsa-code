public class LongestSubstring {
    public static int lengthOfLongestSubstring(String s) {
        int[] lastIndex = new int[128]; // ASCII
        for (int i = 0; i < 128; i++) lastIndex[i] = -1;

        int maxLen = 0, start = 0;
        for (int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }
            lastIndex[c] = end;
            maxLen = Math.max(maxLen, end - start + 1);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("abcabcbb")); // Output: 3
    }
}
