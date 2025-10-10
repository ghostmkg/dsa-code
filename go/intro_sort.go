package main

import (
	"fmt"
	"math"
)

// Introsort entry point (generic for any ordered type)
func IntroSort[T constraints.Ordered](arr []T) {
	if len(arr) <= 1 {
		return
	}
	depthLimit := int(2 * math.Floor(math.Log2(float64(len(arr)))))
	introsortImpl(arr, depthLimit)
}

func introsortImpl[T constraints.Ordered](arr []T, depthLimit int) {
	const INSERTION_THRESHOLD = 16

	n := len(arr)
	if n <= 1 {
		return
	}

	if n <= INSERTION_THRESHOLD {
		insertionSort(arr)
		return
	}

	if depthLimit == 0 {
		heapSort(arr)
		return
	}

	// Partition using median-of-three pivot
	pivot := partitionMedian3(arr)
	introsortImpl(arr[:pivot], depthLimit-1)
	introsortImpl(arr[pivot+1:], depthLimit-1)
}

func insertionSort[T constraints.Ordered](arr []T) {
	for i := 1; i < len(arr); i++ {
		for j := i; j > 0 && arr[j] < arr[j-1]; j-- {
			arr[j], arr[j-1] = arr[j-1], arr[j]
		}
	}
}

func partitionMedian3[T constraints.Ordered](arr []T) int {
	n := len(arr)
	mid := n / 2

	// median-of-three: arr[0], arr[mid], arr[n-1]
	if arr[0] > arr[mid] {
		arr[0], arr[mid] = arr[mid], arr[0]
	}
	if arr[mid] > arr[n-1] {
		arr[mid], arr[n-1] = arr[n-1], arr[mid]
	}
	if arr[0] > arr[mid] {
		arr[0], arr[mid] = arr[mid], arr[0]
	}

	// pivot = arr[mid]
	pivot := arr[mid]
	arr[mid], arr[n-1] = arr[n-1], arr[mid] // move pivot to end
	i := 0
	for j := 0; j < n-1; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[n-1] = arr[n-1], arr[i]
	return i
}

func heapSort[T constraints.Ordered](arr []T) {
	n := len(arr)
	// Build max-heap
	for i := n/2 - 1; i >= 0; i-- {
		siftDown(arr, i, n)
	}
	// Extract elements
	for i := n - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		siftDown(arr, 0, i)
	}
}

func siftDown[T constraints.Ordered](arr []T, start, end int) {
	root := start
	for {
		child := 2*root + 1
		if child >= end {
			break
		}
		swap := root
		if arr[swap] < arr[child] {
			swap = child
		}
		if child+1 < end && arr[swap] < arr[child+1] {
			swap = child + 1
		}
		if swap == root {
			return
		}
		arr[root], arr[swap] = arr[swap], arr[root]
		root = swap
	}
}
