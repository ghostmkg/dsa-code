package main

import "fmt"

func bfs(start int, graph [][]int) {
    n := len(graph)
    visited := make([]bool, n)
    queue := []int{start}
    visited[start] = true

    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:] // dequeue
        fmt.Print(node, " ")

        for _, nei := range graph[node] {
            if !visited[nei] {
                visited[nei] = true
                queue = append(queue, nei) // enqueue
            }
        }
    }
}

func main() {
    graph := [][]int{
        {1, 2},    // 0 → 1, 2
        {0, 3, 4}, // 1 → 0, 3, 4
        {0, 5},    // 2 → 0, 5
        {1},       // 3 → 1
        {1, 5},    // 4 → 1, 5
        {2, 4},    // 5 → 2, 4
    }

    fmt.Print("BFS traversal: ")
    bfs(0, graph)
    fmt.Println()
}
