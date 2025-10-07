#include <iostream>
#include <vector>
using namespace std;

// Function to search target in a rotated sorted array
int searchInRotatedSortedArray(const vector<int>& nums, int target) {
// Function to search target in rotated sorted array
int searchInRotatedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the target
        if (nums[mid] == target) return mid;

        // Determine which part is sorted
        if (nums[left] <= nums[mid]) { // Left part is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in left part
            } else {
                left = mid + 1; // Target is in right part
            }
        } else { // Right part is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in right part
            } else {
                right = mid - 1; // Target is in left part
            }
        }
    }

    return -1; // Target not found

        if (nums[mid] == target) 
            return mid;

        // Check which half is sorted
        if (nums[left] <= nums[mid]) {
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // target lies in left half
            } else {
                left = mid + 1; // target lies in right half
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // target lies in right half
            } else {
                right = mid - 1; // target lies in left half
            }
        }
    }

    return -1; // not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = searchInRotatedSortedArray(nums, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    int result = searchInRotatedArray(nums, target);

    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
