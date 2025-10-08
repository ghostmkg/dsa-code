package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Point struct {
	x, y int
}

type Node struct {
	pos    Point
	g, h   float64
	parent *Node
	idx    int
}

func (n *Node) f() float64 { return n.g + n.h }

type PriorityQueue []*Node

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].f() < pq[j].f() }
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].idx, pq[j].idx = i, j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	node := x.(*Node)
	node.idx = n
	*pq = append(*pq, node)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	node := old[n-1]
	old[n-1] = nil
	node.idx = -1
	*pq = old[0 : n-1]
	return node
}

func heuristic(a, b Point) float64 {
	return math.Abs(float64(a.x-b.x)) + math.Abs(float64(a.y-b.y))
}

func AStar(grid [][]int, start, goal Point) []Point {
	rows, cols := len(grid), len(grid[0])
	dirs := []Point{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

	pq := &PriorityQueue{}
	heap.Init(pq)

	startNode := &Node{pos: start, g: 0, h: heuristic(start, goal)}
	heap.Push(pq, startNode)

	visited := make(map[Point]bool)
	costs := make(map[Point]float64)
	costs[start] = 0

	for pq.Len() > 0 {
		curr := heap.Pop(pq).(*Node)

		if curr.pos == goal {
			path := []Point{}
			for n := curr; n != nil; n = n.parent {
				path = append([]Point{n.pos}, path...)
			}
			return path
		}

		if visited[curr.pos] {
			continue
		}
		visited[curr.pos] = true

		for _, d := range dirs {
			nx, ny := curr.pos.x+d.x, curr.pos.y+d.y
			neighbor := Point{nx, ny}

			if nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] == 1 {
				continue
			}

			newG := curr.g + 1

			if cost, ok := costs[neighbor]; !ok || newG < cost {
				costs[neighbor] = newG
				node := &Node{
					pos:    neighbor,
					g:      newG,
					h:      heuristic(neighbor, goal),
					parent: curr,
				}
				heap.Push(pq, node)
			}
		}
	}

	return nil
}

func main() {
	grid := [][]int{
		{0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0},
	}

	start := Point{0, 0}
	goal := Point{4, 4}

	path := AStar(grid, start, goal)

	if path != nil {
		fmt.Println("Path found:")
		for _, p := range path {
			fmt.Printf("(%d,%d) ", p.x, p.y)
		}
		fmt.Printf("\nSteps: %d\n", len(path)-1)
	} else {
		fmt.Println("No path found")
	}
}
