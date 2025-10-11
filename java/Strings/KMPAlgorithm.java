public class KMPAlgorithm {
    
    public static int kmpSearch(String text, String pattern) {
        if (pattern == null || pattern.isEmpty()) return 0;
        if (text == null || text.isEmpty()) return -1;

        int n = text.length();
        int m = pattern.length();

       
        int[] lps = buildLPS(pattern);

        int i = 0; 
        int j = 0; 

        
        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j; 
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1]; 
                } else {
                    i++;
                }
            }
        }

        return -1; 
    }

    
    private static int[] buildLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    public static void main(String[] args) {
        String text = "abxabcabcaby";
        String pattern = "abcaby";

        int index = kmpSearch(text, pattern);
        System.out.println("Pattern found at index: " + index); 

        System.out.println("Pattern found at index: " + kmpSearch("hello", "ll")); 
        System.out.println("Pattern found at index: " + kmpSearch("aaaaa", "bba")); 
    }
}
