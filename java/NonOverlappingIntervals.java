class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[1],b[1]));
        int count=0,i;
        int[] curr=intervals[0];
        for(i=1; i<intervals.length; i++){
            if(curr[1]>intervals[i][0])
                count++;
            else{
                curr[1]=intervals[i][1];
            }
        }
        return count;
    }
}