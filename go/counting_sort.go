package main

import (
	"fmt"
)

// CountingSort sorts an array of non-negative integers using counting sort algorithm.
func CountingSort(arr []int) []int {
	if len(arr) == 0 {
		return arr
	}

	// Step 1: Find the maximum element in the array
	max := arr[0]
	for _, num := range arr {
		if num > max {
			max = num
		}
	}

	// Step 2: Create a count array
	count := make([]int, max+1)

	// Step 3: Count the occurrences of each element
	for _, num := range arr {
		count[num]++
	}

	// Step 4: Reconstruct the sorted array
	index := 0
	for i, c := range count {
		for c > 0 {
			arr[index] = i
			index++
			c--
		}
	}

	return arr
}

func main() {
	var n int
	fmt.Print("Enter number of elements: ")
	fmt.Scan(&n)

	arr := make([]int, n)
	fmt.Println("Enter elements:")

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	fmt.Println("Original array:", arr)
	sorted := CountingSort(arr)
	fmt.Println("Sorted array:  ", sorted)
}
