public class Longestpalindrome{
    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromCenter(s, i, i);       
            int len2 = expandFromCenter(s, i, i + 1);   
            int len = Math.max(len1, len2);

            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    private static int expandFromCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    public static void main(String[] args) {
        String str = "babad";
        System.out.println("Longest Palindromic Substring: " + longestPalindrome(str));

        str = "cbbd";
        System.out.println("Longest Palindromic Substring: " + longestPalindrome(str));

        str = "a";
        System.out.println("Longest Palindromic Substring: " + longestPalindrome(str));

        str = "forgeeksskeegfor";
        System.out.println("Longest Palindromic Substring: " + longestPalindrome(str));
    }
}
