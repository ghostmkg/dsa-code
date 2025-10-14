/*
 * Kadane's Algorithm - Maximum Subarray Problem
 * 
 * Kadane's algorithm is a dynamic programming approach to solve the maximum subarray problem.
 * It finds the contiguous subarray within a one-dimensional array of numbers that has the 
 * largest sum.
 * 
 * Problem: Given an array of integers, find the contiguous subarray with the largest sum.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Key Insight: At each position, we decide whether to extend the previous subarray or
 * start a new one from the current element.
 * 
 * Author: Hacktoberfest Contributor
 * Date: October 2024
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

class KadaneAlgorithm {
public:
    
    /**
     * Classic Kadane's Algorithm - finds maximum sum of contiguous subarray
     * 
     * @param arr Input array
     * @return Maximum sum of contiguous subarray
     */
    static long long kadaneMaxSum(const vector<int>& arr) {
        if (arr.empty()) return 0;
        
        long long maxEndingHere = arr[0];
        long long maxSoFar = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            // Either extend the existing subarray or start a new one
            maxEndingHere = max((long long)arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
    
    /**
     * Kadane's Algorithm with indices - returns max sum along with start and end indices
     * 
     * @param arr Input array
     * @return Tuple containing {maxSum, startIndex, endIndex}
     */
    static tuple<long long, int, int> kadaneWithIndices(const vector<int>& arr) {
        if (arr.empty()) return make_tuple(0, -1, -1);
        
        long long maxEndingHere = arr[0];
        long long maxSoFar = arr[0];
        int start = 0, end = 0, tempStart = 0;
        
        for (size_t i = 1; i < arr.size(); i++) {
            if (maxEndingHere < 0) {
                maxEndingHere = arr[i];
                tempStart = i;
            } else {
                maxEndingHere += arr[i];
            }
            
            if (maxEndingHere > maxSoFar) {
                maxSoFar = maxEndingHere;
                start = tempStart;
                end = i;
            }
        }
        
        return make_tuple(maxSoFar, start, end);
    }
    
    /**
     * Kadane's Algorithm variant - handles all negative numbers
     * Returns the least negative number if all elements are negative
     * 
     * @param arr Input array
     * @return Maximum sum (or least negative if all negative)
     */
    static long long kadaneAllNegative(const vector<int>& arr) {
        if (arr.empty()) return 0;
        
        long long maxEndingHere = arr[0];
        long long maxSoFar = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            maxEndingHere = max((long long)arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
    
    /**
     * Circular Array Maximum Subarray - handles circular arrays
     * Maximum subarray can be either normal or circular
     * 
     * @param arr Input circular array
     * @return Maximum sum in circular array
     */
    static long long kadaneCircular(const vector<int>& arr) {
        if (arr.empty()) return 0;
        if (arr.size() == 1) return arr[0];
        
        // Case 1: Maximum subarray is non-circular
        long long maxKadane = kadaneMaxSum(arr);
        
        // Case 2: Maximum subarray is circular
        // Total sum - minimum subarray sum
        long long totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // Find minimum subarray sum using modified Kadane's
        long long minEndingHere = arr[0];
        long long minSoFar = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            minEndingHere = min((long long)arr[i], minEndingHere + arr[i]);
            minSoFar = min(minSoFar, minEndingHere);
        }
        
        long long maxCircular = totalSum - minSoFar;
        
        // If all elements are negative, maxCircular would be 0
        // In that case, return maxKadane
        if (maxCircular == 0) {
            return maxKadane;
        }
        
        return max(maxKadane, maxCircular);
    }
    
    /**
     * Maximum Product Subarray - variant of Kadane's for product instead of sum
     * 
     * @param arr Input array
     * @return Maximum product of contiguous subarray
     */
    static long long maxProductSubarray(const vector<int>& arr) {
        if (arr.empty()) return 0;
        
        long long maxEndingHere = arr[0];
        long long minEndingHere = arr[0];  // Keep track of minimum for negative numbers
        long long result = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            // If current element is negative, swap max and min
            if (arr[i] < 0) {
                swap(maxEndingHere, minEndingHere);
            }
            
            maxEndingHere = max((long long)arr[i], maxEndingHere * arr[i]);
            minEndingHere = min((long long)arr[i], minEndingHere * arr[i]);
            
            result = max(result, maxEndingHere);
        }
        
        return result;
    }
    
    /**
     * Maximum Length Subarray with given sum
     * 
     * @param arr Input array
     * @param targetSum Target sum to achieve
     * @return Length of longest subarray with given sum, -1 if not found
     */
    static int maxLengthSubarrayWithSum(const vector<int>& arr, long long targetSum) {
        if (arr.empty()) return -1;
        
        unordered_map<long long, int> sumIndexMap;
        long long currentSum = 0;
        int maxLength = -1;
        
        sumIndexMap[0] = -1; // For subarrays starting from index 0
        
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            
            if (sumIndexMap.find(currentSum - targetSum) != sumIndexMap.end()) {
                maxLength = max(maxLength, i - sumIndexMap[currentSum - targetSum]);
            }
            
            if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
                sumIndexMap[currentSum] = i;
            }
        }
        
        return maxLength;
    }
    
    /**
     * Print the actual maximum subarray
     * 
     * @param arr Input array
     */
    static void printMaxSubarray(const vector<int>& arr) {
        auto result = kadaneWithIndices(arr);
        long long maxSum = get<0>(result);
        int start = get<1>(result);
        int end = get<2>(result);
        
        cout << "Maximum sum: " << maxSum << endl;
        cout << "Subarray: [";
        for (int i = start; i <= end; i++) {
            cout << arr[i];
            if (i < end) cout << ", ";
        }
        cout << "]" << endl;
        cout << "Indices: [" << start << ", " << end << "]" << endl;
    }
    
    /**
     * Brute force solution for verification (O(n²))
     * 
     * @param arr Input array
     * @return Maximum sum of contiguous subarray
     */
    static long long bruteForceSolution(const vector<int>& arr) {
        if (arr.empty()) return 0;
        
        long long maxSum = LLONG_MIN;
        
        for (size_t i = 0; i < arr.size(); i++) {
            long long currentSum = 0;
            for (size_t j = i; j < arr.size(); j++) {
                currentSum += arr[j];
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};

/**
 * Demonstration and testing functions
 */
void demonstrateKadane() {
    cout << "🚀 KADANE'S ALGORITHM DEMONSTRATION" << endl;
    cout << "===================================" << endl;
    
    // Test cases
    vector<vector<int>> testCases = {
        {-2, -3, 4, -1, -2, 1, 5, -3},  // Classic example
        {1, 2, 3, 4, 5},                // All positive
        {-5, -2, -8, -1},               // All negative
        {5, -3, 5},                     // Mixed
        {1, -3, 2, 1, -1},              // Another mixed
        {-2, 1, -3, 4, -1, 2, 1, -5, 4}, // LeetCode example
        {0, 0, 0, 0},                   // All zeros
        {42},                           // Single element
        {}                              // Empty array
    };
    
    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "\n--- Test Case " << (i + 1) << " ---" << endl;
        vector<int>& arr = testCases[i];
        
        if (arr.empty()) {
            cout << "Array: []" << endl;
            cout << "Kadane's result: " << KadaneAlgorithm::kadaneMaxSum(arr) << endl;
            continue;
        }
        
        cout << "Array: [";
        for (size_t j = 0; j < arr.size(); j++) {
            cout << arr[j];
            if (j < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        // Basic Kadane's
        long long kadaneResult = KadaneAlgorithm::kadaneMaxSum(arr);
        cout << "Kadane's result: " << kadaneResult << endl;
        
        // Kadane's with indices
        KadaneAlgorithm::printMaxSubarray(arr);
        
        // Circular variant (for arrays with more than one element)
        if (arr.size() > 1) {
            long long circularResult = KadaneAlgorithm::kadaneCircular(arr);
            cout << "Circular maximum: " << circularResult << endl;
        }
        
        // Maximum product subarray
        long long productResult = KadaneAlgorithm::maxProductSubarray(arr);
        cout << "Maximum product subarray: " << productResult << endl;
        
        // Brute force verification (only for small arrays)
        if (arr.size() <= 10) {
            long long bruteResult = KadaneAlgorithm::bruteForceSolution(arr);
            cout << "Brute force verification: " << bruteResult;
            cout << (bruteResult == kadaneResult ? " ✓" : " ✗") << endl;
        }
        
        cout << string(40, '-') << endl;
    }
}

/**
 * Performance comparison between Kadane's and brute force
 */
void performanceComparison() {
    cout << "\n🏃 PERFORMANCE COMPARISON" << endl;
    cout << "=========================" << endl;
    
    vector<int> sizes = {1000, 5000, 10000, 50000};
    
    for (int size : sizes) {
        // Generate random array
        vector<int> arr(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(-100, 100);
        
        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen);
        }
        
        cout << "\nArray size: " << size << endl;
        
        // Test Kadane's Algorithm
        auto start = clock();
        long long kadaneResult = KadaneAlgorithm::kadaneMaxSum(arr);
        auto kadaneTime = clock() - start;
        
        cout << "Kadane's Algorithm: " << kadaneResult;
        cout << " (Time: " << ((double)kadaneTime / CLOCKS_PER_SEC * 1000) << " ms)" << endl;
        
        // Test brute force only for smaller arrays
        if (size <= 5000) {
            start = clock();
            long long bruteResult = KadaneAlgorithm::bruteForceSolution(arr);
            auto bruteTime = clock() - start;
            
            cout << "Brute Force: " << bruteResult;
            cout << " (Time: " << ((double)bruteTime / CLOCKS_PER_SEC * 1000) << " ms)";
            cout << (bruteResult == kadaneResult ? " ✓" : " ✗") << endl;
            
            double speedup = (double)bruteTime / kadaneTime;
            cout << "Speedup: " << speedup << "x faster" << endl;
        } else {
            cout << "Brute force skipped (too slow for large arrays)" << endl;
        }
    }
}

/**
 * Interactive demo
 */
void interactiveDemo() {
    cout << "\n🎮 INTERACTIVE DEMO" << endl;
    cout << "==================" << endl;
    
    cout << "Enter array size: ";
    int size;
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return;
    }
    
    vector<int> arr(size);
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "\nYour array: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "\nResults:" << endl;
    KadaneAlgorithm::printMaxSubarray(arr);
    
    if (size > 1) {
        cout << "Circular maximum: " << KadaneAlgorithm::kadaneCircular(arr) << endl;
    }
    
    cout << "Maximum product: " << KadaneAlgorithm::maxProductSubarray(arr) << endl;
    
    char choice;
    cout << "\nTry another array? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        interactiveDemo();
    }
}

int main() {
    cout << "Kadane's Algorithm - Maximum Subarray Problem" << endl;
    cout << "=============================================" << endl;
    
    // Run comprehensive demonstration
    demonstrateKadane();
    
    // Performance comparison
    performanceComparison();
    
    // Ask for interactive demo
    char choice;
    cout << "\nWould you like to try the interactive demo? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactiveDemo();
    }
    
    cout << "\n=== ALGORITHM SUMMARY ===" << endl;
    cout << "✅ Time Complexity: O(n)" << endl;
    cout << "✅ Space Complexity: O(1)" << endl;
    cout << "✅ Handles all edge cases" << endl;
    cout << "✅ Multiple variants implemented" << endl;
    cout << "✅ Perfect for competitive programming" << endl;
    cout << "✅ Great for Hacktoberfest 2024!" << endl;
    cout << "\nHappy coding! 🚀" << endl;
    
    return 0;
}

/*
 * Common Applications of Kadane's Algorithm:
 * 
 * 1. Stock Trading: Maximum profit from buying and selling stocks
 * 2. Image Processing: Finding the brightest region in an image
 * 3. Bioinformatics: Finding the most conserved region in DNA sequences  
 * 4. Finance: Maximum gain/loss analysis over time periods
 * 5. Gaming: Maximum score achievable in a sequence of moves
 * 
 * Key Insights:
 * 1. The algorithm maintains two variables: max_ending_here and max_so_far
 * 2. At each step, decide whether to extend the current subarray or start fresh
 * 3. Works for any array with at least one positive number
 * 4. Can be modified for circular arrays, product instead of sum, etc.
 * 
 * Example Walkthrough for array [-2, -3, 4, -1, -2, 1, 5, -3]:
 * 
 * i=0: max_ending_here=-2, max_so_far=-2
 * i=1: max_ending_here=-3, max_so_far=-2  
 * i=2: max_ending_here=4,  max_so_far=4   (start new subarray)
 * i=3: max_ending_here=3,  max_so_far=4
 * i=4: max_ending_here=1,  max_so_far=4
 * i=5: max_ending_here=2,  max_so_far=4
 * i=6: max_ending_here=7,  max_so_far=7   (extend subarray: [4,-1,-2,1,5])
 * i=7: max_ending_here=4,  max_so_far=7
 * 
 * Result: Maximum sum = 7, Subarray = [4, -1, -2, 1, 5]
 */