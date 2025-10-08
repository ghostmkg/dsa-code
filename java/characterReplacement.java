public class characterReplacement {

    public int charReplacement(String s, int k) {
        int[] count = new int[26];
        int maxCount = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - 'A']++;
            maxCount = Math.max(maxCount, count[s.charAt(right) - 'A']);

            while ((right - left + 1) - maxCount > k) {
                count[s.charAt(left) - 'A']--;
                left++;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
    public static void main(String[] args) {
        characterReplacement cr = new characterReplacement();
        String s = "AABABBA";
        int k = 1;
        int result = cr.charReplacement(s, k);
        System.out.println("The length of the longest substring after replacement is: " + result);
    }
}
