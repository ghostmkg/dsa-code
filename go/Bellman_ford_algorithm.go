package main

import (
	"fmt"
	"math"
)

// Edge represents a weighted edge from `from` to `to`
type Edge struct {
	from, to, weight int
}

// Bellman-Ford Algorithm
// Returns distance array and a boolean indicating if a negative cycle exists
func bellmanFord(edges []Edge, V int, start int) ([]int, bool) {
	// Initialize distances
	dist := make([]int, V)
	for i := 0; i < V; i++ {
		dist[i] = math.MaxInt32
	}
	dist[start] = 0

	// Relax all edges V-1 times
	for i := 0; i < V-1; i++ {
		for _, edge := range edges {
			if dist[edge.from] != math.MaxInt32 && dist[edge.from]+edge.weight < dist[edge.to] {
				dist[edge.to] = dist[edge.from] + edge.weight
			}
		}
	}

	// Check for negative weight cycles
	for _, edge := range edges {
		if dist[edge.from] != math.MaxInt32 && dist[edge.from]+edge.weight < dist[edge.to] {
			return dist, true // Negative cycle detected
		}
	}

	return dist, false
}

func main() {
	V := 5 // Number of vertices
	edges := []Edge{
		{0, 1, -1},
		{0, 2, 4},
		{1, 2, 3},
		{1, 3, 2},
		{1, 4, 2},
		{3, 2, 5},
		{3, 1, 1},
		{4, 3, -3},
	}

	start := 0
	dist, hasNegativeCycle := bellmanFord(edges, V, start)

	if hasNegativeCycle {
		fmt.Println("Graph contains a negative weight cycle")
	} else {
		fmt.Println("Shortest distances from node", start, ":")
		for i, d := range dist {
			fmt.Printf("To %d = %d\n", i, d)
		}
	}
}
