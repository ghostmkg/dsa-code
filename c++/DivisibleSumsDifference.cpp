#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

/**
 * Calculates the absolute difference between the sum of divisible and non-divisible elements
 * @param arr: vector of integers
 * @param divisor: the divisor to check divisibility
 * @return: absolute difference between divisible sum and non-divisible sum
 */
long long divisibleSumsDifference(const std::vector<int>& arr, int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Divisor cannot be zero");
    }
    
    long long divisibleSum = 0;
    long long nonDivisibleSum = 0;
    
    for (int num : arr) {
        if (num % divisor == 0) {
            divisibleSum += num;
        } else {
            nonDivisibleSum += num;
        }
    }
    
    return std::abs(divisibleSum - nonDivisibleSum);
}

/**
 * Test function to validate the implementation
 */
void runTests() {
    std::cout << "Running test cases...\n\n";
    
    // Test Case 1: Mixed divisible/non-divisible elements
    std::vector<int> test1 = {10, 15, 20, 25, 30};
    long long result1 = divisibleSumsDifference(test1, 5);
    std::cout << "Test 1 - Mixed elements [10, 15, 20, 25, 30] with divisor 5:\n";
    std::cout << "Divisible sum: 10+15+20+25+30 = 100\n";
    std::cout << "Non-divisible sum: 0\n";
    std::cout << "Absolute difference: " << result1 << "\n";
    assert(result1 == 100);
    std::cout << "✓ Test 1 passed\n\n";
    
    // Test Case 2: Mixed with some non-divisible
    std::vector<int> test2 = {12, 7, 18, 13, 24};
    long long result2 = divisibleSumsDifference(test2, 6);
    std::cout << "Test 2 - Mixed elements [12, 7, 18, 13, 24] with divisor 6:\n";
    std::cout << "Divisible sum: 12+18+24 = 54\n";
    std::cout << "Non-divisible sum: 7+13 = 20\n";
    std::cout << "Absolute difference: " << result2 << "\n";
    assert(result2 == 34);
    std::cout << "✓ Test 2 passed\n\n";
    
    // Test Case 3: All elements divisible
    std::vector<int> test3 = {9, 18, 27, 36};
    long long result3 = divisibleSumsDifference(test3, 9);
    std::cout << "Test 3 - All divisible [9, 18, 27, 36] with divisor 9:\n";
    std::cout << "Divisible sum: 9+18+27+36 = 90\n";
    std::cout << "Non-divisible sum: 0\n";
    std::cout << "Absolute difference: " << result3 << "\n";
    assert(result3 == 90);
    std::cout << "✓ Test 3 passed\n\n";
    
    // Test Case 4: All elements non-divisible
    std::vector<int> test4 = {7, 11, 13, 17};
    long long result4 = divisibleSumsDifference(test4, 5);
    std::cout << "Test 4 - All non-divisible [7, 11, 13, 17] with divisor 5:\n";
    std::cout << "Divisible sum: 0\n";
    std::cout << "Non-divisible sum: 7+11+13+17 = 48\n";
    std::cout << "Absolute difference: " << result4 << "\n";
    assert(result4 == 48);
    std::cout << "✓ Test 4 passed\n\n";
    
    // Test Case 5: Empty array
    std::vector<int> test5 = {};
    long long result5 = divisibleSumsDifference(test5, 3);
    std::cout << "Test 5 - Empty array [] with divisor 3:\n";
    std::cout << "Divisible sum: 0\n";
    std::cout << "Non-divisible sum: 0\n";
    std::cout << "Absolute difference: " << result5 << "\n";
    assert(result5 == 0);
    std::cout << "✓ Test 5 passed\n\n";
    
    // Test Case 6: Negative numbers
    std::vector<int> test6 = {-12, -7, 8, -3, 15};
    long long result6 = divisibleSumsDifference(test6, 3);
    std::cout << "Test 6 - Negative numbers [-12, -7, 8, -3, 15] with divisor 3:\n";
    std::cout << "Divisible sum: -12+(-3)+15 = 0\n";
    std::cout << "Non-divisible sum: -7+8 = 1\n";
    std::cout << "Absolute difference: " << result6 << "\n";
    assert(result6 == 1);
    std::cout << "✓ Test 6 passed\n\n";
    
    // Test Case 7: Single element divisible
    std::vector<int> test7 = {21};
    long long result7 = divisibleSumsDifference(test7, 7);
    std::cout << "Test 7 - Single divisible element [21] with divisor 7:\n";
    std::cout << "Divisible sum: 21\n";
    std::cout << "Non-divisible sum: 0\n";
    std::cout << "Absolute difference: " << result7 << "\n";
    assert(result7 == 21);
    std::cout << "✓ Test 7 passed\n\n";
    
    // Test Case 8: Single element non-divisible
    std::vector<int> test8 = {23};
    long long result8 = divisibleSumsDifference(test8, 7);
    std::cout << "Test 8 - Single non-divisible element [23] with divisor 7:\n";
    std::cout << "Divisible sum: 0\n";
    std::cout << "Non-divisible sum: 23\n";
    std::cout << "Absolute difference: " << result8 << "\n";
    assert(result8 == 23);
    std::cout << "✓ Test 8 passed\n\n";
    
    // Test Case 9: Large numbers
    std::vector<int> test9 = {1000, 2500, 3333, 5000};
    long long result9 = divisibleSumsDifference(test9, 1000);
    std::cout << "Test 9 - Large numbers [1000, 2500, 3333, 5000] with divisor 1000:\n";
    std::cout << "Divisible sum: 1000+5000 = 6000\n";
    std::cout << "Non-divisible sum: 2500+3333 = 5833\n";
    std::cout << "Absolute difference: " << result9 << "\n";
    assert(result9 == 167);
    std::cout << "✓ Test 9 passed\n\n";
    
    std::cout << "All tests passed successfully! ✓\n";
}

/**
 * Interactive function to get user input and calculate the difference
 */
void interactiveMode() {
    int n, divisor;
    std::cout << "\n=== Interactive Mode ===\n";
    std::cout << "Enter the number of elements: ";
    
    if (!(std::cin >> n) || n < 0) {
        std::cout << "Invalid input: number of elements must be a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    
    std::vector<int> arr(n);
    if (n > 0) {
        std::cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
    }
    
    std::cout << "Enter the divisor: ";
    std::cin >> divisor;
    
    if (divisor == 0) {
        std::cout << "Error: Divisor cannot be zero.\n";
        return;
    }
    
    try {
        long long result = divisibleSumsDifference(arr, divisor);
        
        // Show detailed calculation
        long long divisibleSum = 0, nonDivisibleSum = 0;
        std::cout << "\nCalculation details:\n";
        std::cout << "Elements divisible by " << divisor << ": ";
        
        for (int num : arr) {
            if (num % divisor == 0) {
                std::cout << num << " ";
                divisibleSum += num;
            }
        }
        if (divisibleSum == 0) std::cout << "None";
        std::cout << "\nSum of divisible elements: " << divisibleSum << "\n";
        
        std::cout << "Elements not divisible by " << divisor << ": ";
        for (int num : arr) {
            if (num % divisor != 0) {
                std::cout << num << " ";
                nonDivisibleSum += num;
            }
        }
        if (nonDivisibleSum == 0 && divisibleSum != 0) std::cout << "None";
        std::cout << "\nSum of non-divisible elements: " << nonDivisibleSum << "\n";
        
        std::cout << "\nAbsolute difference: |" << divisibleSum << " - " << nonDivisibleSum << "| = " << result << "\n";
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "=== Divisible and Non-divisible Sums Difference Calculator ===\n";
    std::cout << "This program calculates the absolute difference between the sum of\n";
    std::cout << "elements divisible by a given divisor and elements not divisible by it.\n\n";
    
    // Run automated tests
    runTests();
    
    // Interactive mode
    char choice;
    std::cout << "Do you want to try the interactive mode? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactiveMode();
    }
    
    std::cout << "\nProgram completed successfully!\n";
    return 0;
}
