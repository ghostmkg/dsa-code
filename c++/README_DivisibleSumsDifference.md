# Divisible and Non-divisible Sums Difference Implementation

## Overview
This C++ program implements a function that calculates the absolute difference between the sum of elements divisible by a given divisor and the sum of elements not divisible by that divisor.

## Problem Statement
Given an array of integers and a divisor `d`, calculate:
- Sum of all elements divisible by `d`
- Sum of all elements not divisible by `d`
- Return the absolute difference between these two sums

## Features
- ✅ Handles mixed divisible/non-divisible elements
- ✅ Handles all divisible or all non-divisible cases
- ✅ Handles empty arrays
- ✅ Handles negative numbers
- ✅ Handles single element arrays
- ✅ Handles large numbers
- ✅ Error handling for zero divisor
- ✅ Comprehensive test suite with 9 test cases
- ✅ Interactive mode for user input

## Implementation Details

### Function Signature
```cpp
long long divisibleSumsDifference(const std::vector<int>& arr, int divisor)
```

### Parameters
- `arr`: A vector of integers to process
- `divisor`: The divisor to check divisibility against

### Return Value
- Returns the absolute difference between divisible sum and non-divisible sum as `long long`

### Exception Handling
- Throws `std::invalid_argument` if divisor is zero

## Test Cases

### Test 1: Mixed Elements
- **Input**: `[10, 15, 20, 25, 30]`, divisor = `5`
- **Divisible sum**: 100
- **Non-divisible sum**: 0
- **Result**: 100 ✓

### Test 2: Mixed with Some Non-divisible
- **Input**: `[12, 7, 18, 13, 24]`, divisor = `6`
- **Divisible sum**: 54
- **Non-divisible sum**: 20
- **Result**: 34 ✓

### Test 3: All Elements Divisible
- **Input**: `[9, 18, 27, 36]`, divisor = `9`
- **Divisible sum**: 90
- **Non-divisible sum**: 0
- **Result**: 90 ✓

### Test 4: All Elements Non-divisible
- **Input**: `[7, 11, 13, 17]`, divisor = `5`
- **Divisible sum**: 0
- **Non-divisible sum**: 48
- **Result**: 48 ✓

### Test 5: Empty Array
- **Input**: `[]`, divisor = `3`
- **Divisible sum**: 0
- **Non-divisible sum**: 0
- **Result**: 0 ✓

### Test 6: Negative Numbers
- **Input**: `[-12, -7, 8, -3, 15]`, divisor = `3`
- **Divisible sum**: 0
- **Non-divisible sum**: 1
- **Result**: 1 ✓

### Test 7: Single Divisible Element
- **Input**: `[21]`, divisor = `7`
- **Divisible sum**: 21
- **Non-divisible sum**: 0
- **Result**: 21 ✓

### Test 8: Single Non-divisible Element
- **Input**: `[23]`, divisor = `7`
- **Divisible sum**: 0
- **Non-divisible sum**: 23
- **Result**: 23 ✓

### Test 9: Large Numbers
- **Input**: `[1000, 2500, 3333, 5000]`, divisor = `1000`
- **Divisible sum**: 6000
- **Non-divisible sum**: 5833
- **Result**: 167 ✓

## Compilation

### Using g++
```bash
g++ -std=c++11 -Wall -Wextra -o DivisibleSumsDifference.exe DivisibleSumsDifference.cpp
```

### Using MSVC
```bash
cl /EHsc /std:c++11 DivisibleSumsDifference.cpp
```

## Usage

### Running the Program
```bash
./DivisibleSumsDifference.exe
```

The program will:
1. Automatically run all 9 test cases
2. Display detailed results for each test
3. Offer an interactive mode for custom input

### Interactive Mode
When prompted, you can:
1. Enter the number of elements
2. Enter the elements
3. Enter the divisor
4. View detailed calculation breakdown

## Code Quality
- ✅ No compilation warnings with `-Wall -Wextra`
- ✅ Proper error handling
- ✅ Comprehensive documentation
- ✅ Clean, readable code
- ✅ Efficient O(n) time complexity
- ✅ O(1) space complexity (excluding input)

## Algorithm Complexity
- **Time Complexity**: O(n) - Single pass through the array
- **Space Complexity**: O(1) - Only uses two variables for sums

## Requirements Met
✅ Input: Array of integers and divisor d  
✅ Output: Absolute difference between divisible and non-divisible sums  
✅ Test Cases: All required scenarios covered  
✅ Mixed divisible/non-divisible elements  
✅ All divisible or all non-divisible  
✅ Empty array  
✅ Negative numbers  
✅ Additional edge cases (single element, large numbers)

## Author
Implementation for Issue #166

## License
See repository LICENSE file