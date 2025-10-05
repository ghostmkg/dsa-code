package main

import "fmt"

func dfs(node int, visited []bool, graph [][]int) {
    visited[node] = true
    fmt.Print(node, " ")

    for _, nei := range graph[node] {
        if !visited[nei] {
            dfs(nei, visited, graph)
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

    n := len(graph)
    visited := make([]bool, n)

    fmt.Print("DFS traversal: ")
    dfs(0, visited, graph)
    fmt.Println()
}
