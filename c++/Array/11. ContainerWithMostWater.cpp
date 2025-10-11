#include<iostream>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, area);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;

    }
};