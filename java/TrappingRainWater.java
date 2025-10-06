class Solution {
    public int trap(int[] h) {


        int[] l = new int[h.length];
        int[] r = new int[h.length];

        l[0] = h[0];
        r[h.length - 1] = h[h.length - 1];


        for(int i = 1; i <= h.length-1; i++){
           
            l[i] = Math.max(h[i], l[i-1]);
        }


         for(int i = h.length - 2; i >= 0; i--){
          
            r[i] = Math.max(h[i], r[i+1]);
        }

      int sum = 0;
     

      for(int i = 0; i < h.length; i++){
          sum += Math.min(l[i], r[i]) - h[i];
      }
        return sum;
        
    }
}
