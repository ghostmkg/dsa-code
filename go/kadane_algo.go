package main

import "fmt"

// Function implementing Kadane's Algorithm
func kadane(arr []int) int {
    maxSum := arr[0]
    currentSum := arr[0]

    for i := 1; i < len(arr); i++ {
        // Update current sum
        if currentSum < 0 {
            currentSum = arr[i]
        } else {
            currentSum += arr[i]
        }

        // Update max sum
        if currentSum > maxSum {
            maxSum = currentSum
        }
    }

    return maxSum
}

func main() {
    arr := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
    result := kadane(arr)
    fmt.Println("Maximum Subarray Sum:", result)
}
