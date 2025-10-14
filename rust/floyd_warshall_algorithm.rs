/**
 * Floyd-Warshall Algorithm Implementation
 * 
 * Problem: All-Pairs Shortest Path Problem
 * Source: Classic Graph Algorithm
 * Approach: Dynamic Programming with 3 nested loops
 * Time Complexity: O(V^3) where V is number of vertices
 * Space Complexity: O(V^2) for distance matrix
 * 
 * The Floyd-Warshall algorithm finds shortest paths between all pairs of vertices
 * in a weighted graph. It can handle negative weights but not negative cycles.
 */

use std::collections::HashMap;
use std::cmp;

#[derive(Debug, Clone)]
pub struct Graph {
    vertices: usize,
    edges: Vec<Vec<Option<i32>>>,
}

impl Graph {
    /// Create a new graph with given number of vertices
    pub fn new(vertices: usize) -> Self {
        let mut edges = vec![vec![None; vertices]; vertices];
        
        // Initialize diagonal with 0 (distance from vertex to itself)
        for i in 0..vertices {
            edges[i][i] = Some(0);
        }
        
        Self { vertices, edges }
    }
    
    /// Add a directed edge from u to v with given weight
    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        if u < self.vertices && v < self.vertices {
            self.edges[u][v] = Some(weight);
        }
    }
    
    /// Add an undirected edge between u and v with given weight
    pub fn add_undirected_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.add_edge(u, v, weight);
        self.add_edge(v, u, weight);
    }
    
    /// Get the number of vertices
    pub fn vertices(&self) -> usize {
        self.vertices
    }
    
    /// Get the adjacency matrix
    pub fn get_adjacency_matrix(&self) -> &Vec<Vec<Option<i32>>> {
        &self.edges
    }
}

pub struct FloydWarshall {
    graph: Graph,
    distance: Vec<Vec<Option<i32>>>,
    next: Vec<Vec<Option<usize>>>,
}

impl FloydWarshall {
    /// Create a new Floyd-Warshall solver for the given graph
    pub fn new(graph: Graph) -> Self {
        let vertices = graph.vertices();
        let distance = graph.get_adjacency_matrix().clone();
        let next = vec![vec![None; vertices]; vertices];
        
        Self { graph, distance, next }
    }
    
    /// Run Floyd-Warshall algorithm to find all-pairs shortest paths
    pub fn solve(&mut self) -> Result<(), String> {
        let vertices = self.graph.vertices();
        
        // Initialize next matrix for path reconstruction
        for i in 0..vertices {
            for j in 0..vertices {
                if self.distance[i][j].is_some() && i != j {
                    self.next[i][j] = Some(j);
                }
            }
        }
        
        // Floyd-Warshall algorithm: try all intermediate vertices
        for k in 0..vertices {
            for i in 0..vertices {
                for j in 0..vertices {
                    // If there's a path from i to k and from k to j
                    if let (Some(distance_ik), Some(distance_kj)) = 
                        (self.distance[i][k], self.distance[k][j]) {
                        
                        // Check if current path through k is better
                        let new_distance = distance_ik + distance_kj;
                        
                        match self.distance[i][j] {
                            Some(current_distance) => {
                                if new_distance < current_distance {
                                    self.distance[i][j] = Some(new_distance);
                                    self.next[i][j] = self.next[i][k];
                                }
                            }
                            None => {
                                self.distance[i][j] = Some(new_distance);
                                self.next[i][j] = self.next[i][k];
                            }
                        }
                    }
                }
            }
        }
        
        // Check for negative cycles
        for i in 0..vertices {
            if self.distance[i][i].unwrap_or(0) < 0 {
                return Err(format!("Negative cycle detected involving vertex {}", i));
            }
        }
        
        Ok(())
    }
    
    /// Get shortest distance from vertex u to vertex v
    pub fn get_distance(&self, u: usize, v: usize) -> Option<i32> {
        if u < self.graph.vertices() && v < self.graph.vertices() {
            self.distance[u][v]
        } else {
            None
        }
    }
    
    /// Get the shortest path from vertex u to vertex v
    pub fn get_path(&self, u: usize, v: usize) -> Option<Vec<usize>> {
        if u >= self.graph.vertices() || v >= self.graph.vertices() {
            return None;
        }
        
        if self.distance[u][v].is_none() {
            return None; // No path exists
        }
        
        let mut path = Vec::new();
        let mut current = u;
        
        path.push(current);
        
        while let Some(next_vertex) = self.next[current][v] {
            if current == v {
                break;
            }
            current = next_vertex;
            path.push(current);
        }
        
        Some(path)
    }
    
    /// Print the distance matrix
    pub fn print_distance_matrix(&self) {
        println!("Shortest distances between all pairs:");
        println!("{:>4}", "");
        
        for i in 0..self.graph.vertices() {
            print!("{:>4}", i);
        }
        println!();
        
        for i in 0..self.graph.vertices() {
            print!("{:>4}", i);
            for j in 0..self.graph.vertices() {
                match self.distance[i][j] {
                    Some(d) => print!("{:>4}", d),
                    None => print!("{:>4}", "∞"),
                }
            }
            println!();
        }
    }
    
    /// Print all shortest paths
    pub fn print_all_paths(&self) {
        println!("\nShortest paths between all pairs:");
        
        for i in 0..self.graph.vertices() {
            for j in 0..self.graph.vertices() {
                if i != j {
                    if let Some(path) = self.get_path(i, j) {
                        let distance = self.distance[i][j].unwrap();
                        println!("{} -> {}: distance = {}, path = {:?}", 
                                i, j, distance, path);
                    } else {
                        println!("{} -> {}: No path exists", i, j);
                    }
                }
            }
        }
    }
    
    /// Check if graph has negative cycle
    pub fn has_negative_cycle(&self) -> bool {
        for i in 0..self.graph.vertices() {
            if let Some(distance) = self.distance[i][i] {
                if distance < 0 {
                    return true;
                }
            }
        }
        false
    }
}

/// Utility function to create a sample graph for testing
pub fn create_sample_graph() -> Graph {
    let mut graph = Graph::new(4);
    
    // Add edges (directed graph)
    graph.add_edge(0, 1, 3);
    graph.add_edge(0, 2, 6);
    graph.add_edge(0, 3, 15);
    graph.add_edge(1, 2, -2);
    graph.add_edge(2, 3, 2);
    graph.add_edge(3, 0, 1);
    
    graph
}

/// Utility function to create a graph with negative cycle
pub fn create_negative_cycle_graph() -> Graph {
    let mut graph = Graph::new(3);
    
    graph.add_edge(0, 1, 1);
    graph.add_edge(1, 2, -3);
    graph.add_edge(2, 0, 1);
    
    graph
}

#[cfg(test)]
mod tests {
    use super::*;
    
    #[test]
    fn test_floyd_warshall_basic() {
        let graph = create_sample_graph();
        let mut fw = FloydWarshall::new(graph);
        
        assert!(fw.solve().is_ok());
        
        // Test some known distances
        assert_eq!(fw.get_distance(0, 1), Some(3));
        assert_eq!(fw.get_distance(0, 2), Some(1)); // 0->1->2 = 3+(-2) = 1
        assert_eq!(fw.get_distance(0, 3), Some(3)); // 0->1->2->3 = 3+(-2)+2 = 3
    }
    
    #[test]
    fn test_floyd_warshall_negative_cycle() {
        let graph = create_negative_cycle_graph();
        let mut fw = FloydWarshall::new(graph);
        
        assert!(fw.solve().is_err());
        assert!(fw.has_negative_cycle());
    }
    
    #[test]
    fn test_path_reconstruction() {
        let graph = create_sample_graph();
        let mut fw = FloydWarshall::new(graph);
        
        assert!(fw.solve().is_ok());
        
        let path = fw.get_path(0, 3);
        assert!(path.is_some());
        let path = path.unwrap();
        assert_eq!(path[0], 0);
        assert_eq!(path[path.len() - 1], 3);
    }
}

fn main() {
    println!("=== Floyd-Warshall All-Pairs Shortest Path Algorithm ===\n");
    
    // Test with sample graph
    println!("Testing with sample graph:");
    let graph = create_sample_graph();
    let mut fw = FloydWarshall::new(graph);
    
    match fw.solve() {
        Ok(_) => {
            fw.print_distance_matrix();
            fw.print_all_paths();
            
            // Test specific queries
            println!("\nSpecific queries:");
            for i in 0..4 {
                for j in 0..4 {
                    if i != j {
                        if let Some(distance) = fw.get_distance(i, j) {
                            println!("Distance from {} to {}: {}", i, j, distance);
                        }
                    }
                }
            }
        }
        Err(e) => {
            println!("Error: {}", e);
        }
    }
    
    // Test with negative cycle graph
    println!("\n" + "=".repeat(50));
    println!("Testing with negative cycle graph:");
    let graph = create_negative_cycle_graph();
    let mut fw = FloydWarshall::new(graph);
    
    match fw.solve() {
        Ok(_) => {
            println!("No negative cycle detected");
        }
        Err(e) => {
            println!("Error: {}", e);
        }
    }
    
    // Performance test
    println!("\n" + "=".repeat(50));
    println!("Performance test with larger graph:");
    let mut large_graph = Graph::new(100);
    
    // Add random edges
    for i in 0..100 {
        for j in 0..100 {
            if i != j && (i + j) % 7 == 0 {
                large_graph.add_edge(i, j, (i as i32 + j as i32) % 20 - 10);
            }
        }
    }
    
    let mut fw = FloydWarshall::new(large_graph);
    let start_time = std::time::Instant::now();
    
    match fw.solve() {
        Ok(_) => {
            let duration = start_time.elapsed();
            println!("Floyd-Warshall completed in {:?}", duration);
            println!("Graph has {} vertices", fw.graph.vertices());
        }
        Err(e) => {
            println!("Error: {}", e);
        }
    }
}
