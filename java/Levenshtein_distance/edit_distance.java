class Solution {
    /** 
        * Buri Buri: "Shino-suke, this function will tell us how many changes we need to 
        * turn one word into another. It's called Levenshtein distance!"  
        * Shino-suke: "Ehhh? Sounds like some alien name… is it tasty?"  
        */
       public int minDistance(String s, String t) {
           int n = s.length();
           int m = t.length();
           
           // Buri Buri: "We’ll use a 2D table, dp, where dp[i][j] means 
           // ‘minimum edits to convert first i letters of s into first j letters of t.’"
           int[][] dp = new int[n+1][m+1];
   
           // Buri Buri: "First, if t is empty, we must delete everything from s."  
           // Shino-suke: "So we just keep pressing backspace, right?"  
           for (int i = 0; i <= n; i++) {
               dp[i][0] = i; 
           }
   
           // Buri Buri: "And if s is empty, we need to insert all characters of t."  
           // Shino-suke: "Like typing the whole thing from scratch… boring~"  
           for (int j = 0; j <= m; j++) {
               dp[0][j] = j; 
           }
   
           // Buri Buri: "Now, let’s fill the dp table cell by cell."  
           // Shino-suke: "Ughhh homework again…"
           for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= m; j++) {
                   if (s.charAt(i-1) == t.charAt(j-1)) {
                       // Buri Buri: "If letters match, no need to change, copy diagonal value."  
                       // Shino-suke: "Finally something easy!"
                       dp[i][j] = dp[i-1][j-1];
                   } else {
                       // Buri Buri: "Else we try 3 things: Insert, Delete, Replace."  
                       // Shino-suke: "So much effort just to make words same… I’d rather nap."
                       int insertCost = dp[i][j-1] + 1;
                       int deleteCost = dp[i-1][j] + 1;
                       int replaceCost = dp[i-1][j-1] + 1;
                       dp[i][j] = Math.min(insertCost, Math.min(deleteCost, replaceCost));
                   }
               }
           }
           // Buri Buri: "And voila! dp[n][m] is the answer!"  
           // Shino-suke: "Yay! Let’s eat choco chips now~"
           return dp[n][m];
       }
   
       /**
        * Buri Buri: "Shino-suke, sometimes memory is precious!  
        * This version only remembers two rows instead of whole dp table."  
        * Shino-suke: "So like saving pocket money, huh?"  
        */
       public int minDistanceOptimized(String s, String t) {
           int n = s.length();
           int m = t.length();
           if (n < m) {
               return minDistanceOptimized(t, s);
           }
           int[] prev = new int[m+1];
           int[] curr = new int[m+1];
           
           // Initialize base row
           for (int j = 0; j <= m; j++) {
               prev[j] = j;
           }
   
           for (int i = 1; i <= n; i++) {
               curr[0] = i;
               for (int j = 1; j <= m; j++) {
                   if (s.charAt(i-1) == t.charAt(j-1)) {
                       curr[j] = prev[j-1];
                   } else {
                       int insertCost = curr[j-1] + 1;
                       int deleteCost = prev[j] + 1;
                       int replaceCost = prev[j-1] + 1;
                       curr[j] = Math.min(insertCost, Math.min(deleteCost, replaceCost));
                   }
               }
               // Swap arrays
               int[] temp = prev;
               prev = curr;
               curr = temp;
           }
           return prev[m];
       }
   
       /**
           public static void main(String[] args) {
           EditDistance solver = new EditDistance();
           String word1 = "horse";
           String word2 = "ros";
           
           // Buri Buri: "Let’s test our magic with horse → ros."  
           // Shino-suke: "Heheheh, poor horse, losing letters like hair!"  
           System.out.println("Edit distance between \"" + word1 + "\" and \"" + word2 + "\": " +
                               solver.minDistance(word1, word2));
           // Expect 3
       } **/
   }