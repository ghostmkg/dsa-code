#include <iostream>
#include <vector>
using namespace std;


// Function to perform binary search in a sorted array
int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow

        if (nums[mid] == target)
            return mid; // Target found
        else if (nums[mid] < target)
            left = mid + 1; // Search in right half
        else
            right = mid - 1; // Search in left half
    }

    return -1; // Target not found
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int index = binarySearch(nums, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

// Function to perform Binary Search
int searchInSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoid overflow
        if (nums[mid] == target) {
            return mid; // found target
        } else if (nums[mid] < target) {
            left = mid + 1; // search right half
        } else {
            right = mid - 1; // search left half
        }
    }

    return -1; // target not found
}

int main() {
    // Example input
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = searchInSortedArray(nums, target);

    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
