public class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int[] testNumbers = {1, 2, 3, 4, 8, 16, 18, 32, 64, -2, 0};
        
        for (int num : testNumbers) {
            System.out.println(num + " -> " + sol.isPowerOfTwo(num));
        }
    }
}
