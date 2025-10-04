class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] pse = new int[n];
        int[] nse = new int[n];
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        pse[0] = -1;
        for(int i = 1 ; i < n ; i++){
            while(!st.isEmpty() && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            if(st.isEmpty()){
                pse[i] = -1;
            }
            else pse[i] = st.peek();
            st.push(i);
        }
        while(!st.isEmpty()) st.pop();
        st.push(n-1);
        nse[n-1] = n;
        for(int i = n-2 ; i >= 0 ; i--){
            while(!st.isEmpty() && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            if(st.isEmpty()) nse[i] = n;
            else nse[i] = st.peek();
            st.push(i);
        }
        for(int i = 0 ; i < n ; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i]*width;
            maxArea = Math.max(maxArea,area);
        }
        return maxArea;
    }
}