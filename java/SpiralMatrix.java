// https://leetcode.com/problems/spiral-matrix-ii/

import java.util.*;

class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num = 1;
        
        while (left <= right && top <= bottom) {
            // fill top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;
            
            // fill right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;
            
            // fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }
            
            // fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1) (ignoring the output matrix)