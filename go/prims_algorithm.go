package main

import (
	"container/heap"
	"fmt"
	"math"
)

// Edge represents an edge to a neighbor with a weight
type Edge struct {
	to, weight int
}

// PriorityQueueItem for min-heap
type PriorityQueueItem struct {
	node, weight int
}

// Min-heap implementation
type PriorityQueue []PriorityQueueItem

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].weight < pq[j].weight
}
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(PriorityQueueItem))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// Prim's Algorithm
func primMST(graph [][]Edge, start int) int {
	n := len(graph)
	visited := make([]bool, n)
	pq := &PriorityQueue{}
	heap.Init(pq)

	heap.Push(pq, PriorityQueueItem{node: start, weight: 0})
	totalWeight := 0

	for pq.Len() > 0 {
		cur := heap.Pop(pq).(PriorityQueueItem)
		u := cur.node
		w := cur.weight

		if visited[u] {
			continue
		}

		visited[u] = true
		totalWeight += w

		for _, edge := range graph[u] {
			if !visited[edge.to] {
				heap.Push(pq, PriorityQueueItem{node: edge.to, weight: edge.weight})
			}
		}
	}

	return totalWeight
}

func main() {
	/*
		Graph (undirected weighted):
		0 --2-- 1
		0 --3-- 3
		1 --2-- 2
		1 --4-- 3
		2 --1-- 3
	*/

	graph := [][]Edge{
		{{1, 2}, {3, 3}},    // 0
		{{0, 2}, {2, 2}, {3, 4}}, // 1
		{{1, 2}, {3, 1}},    // 2
		{{0, 3}, {1, 4}, {2, 1}}, // 3
	}

	total := primMST(graph, 0)
	fmt.Println("Total weight of MST:", total)
}
