#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of target
int firstOccurrence(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;      // Potential first occurrence
            right = mid - 1;   // Move left to find earlier occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;    // Move right
        } else {
            right = mid - 1;   // Move left
        }
    }

    return result;
}

// Function to find the last occurrence of target
int lastOccurrence(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;      // Potential last occurrence
            left = mid + 1;    // Move right to find later occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;    // Move right
        } else {
            right = mid - 1;   // Move left
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);

    if (first != -1)
        cout << "First occurrence: " << first << endl;
    else
        cout << "Element not found" << endl;

    if (last != -1)
        cout << "Last occurrence: " << last << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
