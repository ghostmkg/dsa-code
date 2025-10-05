package main

import (
    "container/heap"
    "fmt"
    "math"
)


type Edge struct {
    to     int
    weight int
}


type PriorityQueueItem struct {
    node     int
    distance int
}


type PriorityQueue []PriorityQueueItem

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i].distance < pq[j].distance
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

// Dijkstra’s Algorithm
func dijkstra(graph [][]Edge, start int) []int {
    n := len(graph)
    dist := make([]int, n)
    for i := 0; i < n; i++ {
        dist[i] = math.MaxInt32 // infinity
    }
    dist[start] = 0

    pq := &PriorityQueue{}
    heap.Init(pq)
    heap.Push(pq, PriorityQueueItem{node: start, distance: 0})

    for pq.Len() > 0 {
        cur := heap.Pop(pq).(PriorityQueueItem)
        u := cur.node
        d := cur.distance

        // Skip if we already found a better path
        if d > dist[u] {
            continue
        }

        // Relax edges
        for _, edge := range graph[u] {
            v := edge.to
            w := edge.weight
            if dist[u]+w < dist[v] {
                dist[v] = dist[u] + w
                heap.Push(pq, PriorityQueueItem{node: v, distance: dist[v]})
            }
        }
    }

    return dist
}

func main() {
    /*
       Example graph (undirected):
       0 --4--> 1
       0 --1--> 2
       2 --2--> 1
       1 --1--> 3
       2 --5--> 3

       Represented as adjacency list:
    */
    graph := [][]Edge{
        {{1, 4}, {2, 1}},    // edges from 0
        {{0, 4}, {2, 2}, {3, 1}}, // edges from 1
        {{0, 1}, {1, 2}, {3, 5}}, // edges from 2
        {{1, 1}, {2, 5}},    // edges from 3
    }

    start := 0
    dist := dijkstra(graph, start)

    fmt.Printf("Shortest distances from node %d:\n", start)
    for i, d := range dist {
        fmt.Printf("To %d = %d\n", i, d)
    }
}
