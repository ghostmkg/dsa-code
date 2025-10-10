use std::f64;

#[derive(Debug)]
struct Edge {
    src: usize,
    dest: usize,
    weight: f64,
}

fn bellman_ford(vertices: usize, edges: &Vec<Edge>, src: usize) -> Option<Vec<f64>> {
    let mut dist = vec![f64::INFINITY; vertices];
    dist[src] = 0.0;

    // Step 1: Relax edges |V| - 1 times
    for _ in 0..vertices - 1 {
        let mut updated = false;
        for edge in edges.iter() {
            if dist[edge.src] + edge.weight < dist[edge.dest] {
                dist[edge.dest] = dist[edge.src] + edge.weight;
                updated = true;
            }
        }
        // Optimization: if no update in a full pass, stop early
        if !updated {
            break;
        }
    }

    // Step 2: Detect negative weight cycles
    for edge in edges.iter() {
        if dist[edge.src] + edge.weight < dist[edge.dest] {
            println!("Graph contains a negative weight cycle!");
            return None;
        }
    }

    Some(dist)
}

fn main() {
    // Example graph (directed, weighted)
    let vertices = 5;
    let edges = vec![
        Edge { src: 0, dest: 1, weight: -1.0 },
        Edge { src: 0, dest: 2, weight: 4.0 },
        Edge { src: 1, dest: 2, weight: 3.0 },
        Edge { src: 1, dest: 3, weight: 2.0 },
        Edge { src: 1, dest: 4, weight: 2.0 },
        Edge { src: 3, dest: 2, weight: 5.0 },
        Edge { src: 3, dest: 1, weight: 1.0 },
        Edge { src: 4, dest: 3, weight: -3.0 },
    ];

    let source = 0;
    match bellman_ford(vertices, &edges, source) {
        Some(distances) => {
            println!("Vertex\tDistance from Source ({})", source);
            for (i, &d) in distances.iter().enumerate() {
                if d == f64::INFINITY {
                    println!("{}\t{}", i, "∞");
                } else {
                    println!("{}\t{:.1}", i, d);
                }
            }
        }
        None => println!("Negative weight cycle detected, no valid shortest paths!"),
    }
}
