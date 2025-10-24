import java.util.Arrays;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length; 
         Arrays.sort(potions);
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
             //int[] temp = Arrays.copyOf(potions, potions.length);
              int c=0;
            int lo=0,hi=m-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if((long)spells[i]*potions[mid] >= success){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            ans[i] = m-lo;      
        }
        return ans;
    }
}