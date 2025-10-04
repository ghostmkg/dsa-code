class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        int i;

        int curr[] = intervals[0];
        for(i=1; i< intervals.length; i++){
            if(curr[1]>=intervals[i][0]){
                curr[1] = Math.max(intervals[i][1],curr[1]);
            }
            else{
                res.add(curr);
                curr = intervals[i];
            }
        }
        res.add(curr);
        return res.toArray(new int[res.size()][]);
    }
}