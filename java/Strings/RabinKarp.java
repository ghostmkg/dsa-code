public class RabinKarp {
    public static int rabinKarp(String text, String pattern) {
        if (text == null || pattern == null) return -1;
        int n = text.length(), m = pattern.length();
        if (m > n) return -1;

        int base = 256;               
        int mod = 101;              

        int patternHash = 0;          
        int textHash = 0;             
        int h = 1;                    

        
        for (int i = 0; i < m - 1; i++)
            h = (h * base) % mod;

        
        for (int i = 0; i < m; i++) {
            patternHash = (base * patternHash + pattern.charAt(i)) % mod;
            textHash = (base * textHash + text.charAt(i)) % mod;
        }

        
        for (int i = 0; i <= n - m; i++) {
           
            if (patternHash == textHash) {
               
                int j;
                for (j = 0; j < m; j++) {
                    if (text.charAt(i + j) != pattern.charAt(j))
                        break;
                }
                if (j == m) return i; 
            }

           
            if (i < n - m) {
                textHash = (base * (textHash - text.charAt(i) * h) + text.charAt(i + m)) % mod;

                
                if (textHash < 0)
                    textHash += mod;
            }
        }
        return -1; 
    }

    public static void main(String[] args) {
        String text = "ABCCDDAEFG";
        String pattern = "CDD";
        int index = rabinKarp(text, pattern);
        System.out.println("Pattern found at index: " + index); 

        System.out.println("Pattern found at index: " + rabinKarp("hello", "ll")); 
        System.out.println("Pattern found at index: " + rabinKarp("aaaaa", "bba")); 
    }
}
