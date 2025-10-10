use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    position: usize,
}

// Implement `Ord` for min-heap using BinaryHeap
impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        // Notice we flip the ordering here
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Edge structure
#[derive(Copy, Clone)]
struct Edge {
    node: usize,
    weight: usize,
}

// Dijkstra’s Algorithm
fn dijkstra(graph: &Vec<Vec<Edge>>, start: usize) -> Vec<usize> {
    let n = graph.len();
    let mut dist = vec![usize::MAX; n];
    let mut heap = BinaryHeap::new();

    dist[start] = 0;
    heap.push(State { cost: 0, position: start });

    while let Some(State { cost, position }) = heap.pop() {
        if cost > dist[position] {
            continue;
        }

        for edge in &graph[position] {
            let next = State { cost: cost + edge.weight, position: edge.node };
            if next.cost < dist[next.position] {
                dist[next.position] = next.cost;
                heap.push(next);
            }
        }
    }

    dist
}

fn main() {
    // Graph represented as adjacency list
    // Each node has a vector of edges (neighbor, weight)
    let graph = vec![
        vec![Edge { node: 1, weight: 4 }, Edge { node: 2, weight: 1 }],
        vec![Edge { node: 3, weight: 1 }],
        vec![Edge { node: 1, weight: 2 }, Edge { node: 3, weight: 5 }],
        vec![],
    ];

    let start = 0;
    let distances = dijkstra(&graph, start);

    for (i, &d) in distances.iter().enumerate() {
        if d == usize::MAX {
            println!("Vertex {} is unreachable", i);
        } else {
            println!("Distance from {} to {} is {}", start, i, d);
        }
    }
}
