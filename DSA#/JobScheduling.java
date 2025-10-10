// // <<<< Maximum Profit in Job Scheduling >>>>

// /* You are given n jobs, where every job is represented by:
//    i. startTime[i]: the start time of the job.
//    ii. endTime[i]: the end time of the job.
//    iii. profit[i]: the profit you earn by completing the job.
//    Two jobs cannot be taken that overlap in time.
//    Return the maximum profit you can earn such that there are no two overlapping jobs in your selected subset.
   
//    Note: A job ending at time X is allowed to overlap with another job that starts exactly at time X. */



// // <<<< Solution >>>>

// /**
//  * This implementation uses a combination of dynamic programming with memoization
//  * and binary search for an efficient O(N log N) solution.
//  */


import java.util.Arrays;
import java.util.Comparator;

public class JobScheduling {

    static class Job {
        int s, e, p;
        Job(int s, int e, int p) { this.s = s; this.e = e; this.p = p; }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) jobs[i] = new Job(startTime[i], endTime[i], profit[i]);

        Arrays.sort(jobs, Comparator.comparingInt(j -> j.s));
        int[] starts = new int[n];
        for (int i = 0; i < n; i++) starts[i] = jobs[i].s;
        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            int next = findNextJob(starts, jobs[i].e);
            dp[i] = Math.max(jobs[i].p + dp[next], dp[i + 1]); // take or skip
        }
        return dp[0];
    }

    private int findNextJob(int[] arr, int target) {
        int l = 0, r = arr.length - 1, ans = arr.length;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= target) { ans = m; r = m - 1; } else l = m + 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        JobScheduling js = new JobScheduling();
        int[] start = {1, 2, 3};
        int[] end   = {3, 4, 5};
        int[] prof  = {50, 10, 40};
        System.out.println("Maximum Profit = " + js.jobScheduling(start, end, prof));
    }
}
