public class STRSTR {
    public static int strStr(String haystack, String needle) {
        if (needle.isEmpty()) return 0;
        int hLen = haystack.length(), nLen = needle.length();

        for (int i = 0; i <= hLen - nLen; i++) {
            if (haystack.substring(i, i + nLen).equals(needle)) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(strStr("sadbutsad", "sad")); 
        System.out.println(strStr("leetcode", "leeto")); 
        System.out.println(strStr("hello", "ll"));       
    }
}
