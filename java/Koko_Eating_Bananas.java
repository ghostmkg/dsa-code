// Below is the Java implementation for the problem "Koko Eating Bananas" using binary search to find the minimum eating speed.
// Problem link: https://leetcode.com/problems/koko-eating-bananas/description/
// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile.
// Space Complexity: O(1)
// This code solves the problem efficiently by narrowing down the possible eating speeds using binary search.

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = 0;
        int min = Integer.MAX_VALUE;

        // finding the maximum pile to set the upper limit for binary search
        for (int b : piles) {
            if (b > max) {
                max = b;
            }
        }

        // setting the search space for binary search
        long l = 1, r = max;

        // implementing binary search to find the minimum eating speed
        while (l <= r) {
            long mid = (l + r) / 2;

            long currhr = verify(mid, piles);

            if (currhr > h) {
                l = mid + 1;
            } else {
                // updating the minimum speed found so far so that we have the least possible speed
                min = (int) Math.min(min, mid);
                r = mid-1;
            }
        }

        return min;
    }

    // helper function to calculate the hours needed at a given speed
    private long verify(long num, int[] piles) {
        long hr = 0;

        for (int p : piles) {
            hr += (p + num - 1) / num;
        }

        return hr;
    }
}