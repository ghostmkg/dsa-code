public class TrappingRainWater {
    public static void main(String[] args) {
        int[] arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

        int waterTrapped = findTrappedRainWater(arr);
        System.out.println("Water trapped: " + waterTrapped);
    }

    public static int findTrappedRainWater(int[] arr) {
        int n = arr.length;
        int[] left = new int[n]; 
        int[] right = new int[n]; 

        left[0] = arr[0];
        for(int i=1;i<n;i++) {
            left[i] = Math.max(left[i-1], arr[i]);
        }
        
        right[n-1] = arr[n-1];
        for(int i=n-2;i>0;i--) {
            right[i] = Math.max(right[i+1], arr[i]);
        }

        int waterTrapped = 0;
        for(int i=1;i<n-1;i++) {
            int minHeight = Math.min(left[i], right[i]);
            if(minHeight > arr[i])
                waterTrapped += (minHeight - arr[i]);
        }

        return waterTrapped;
    }
}
