#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // Find the pivot: the first number from the right that is smaller than its neighbor.
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        // If a pivot exists, we can find the next permutation.
        if (i >= 0) {
            int j = n - 1;
            // find the smallest number to the right of the pivot that's larger than pivot
            while (arr[j] <= arr[i]) {
                j--;
            }
            // Swap them.
            swap(arr[i], arr[j]);
        }

        // When original position of pivot is found revert the part of the array after the pivot
        // If no pivot was found, this reverses the whole array to the smallest permutation.
        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {1, 3, 5, 4, 2};

    cout << "Original: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    
    sol.nextPermutation(numbers);

    cout << "\nNext:     ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}