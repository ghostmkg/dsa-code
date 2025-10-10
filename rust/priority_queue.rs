use std::collections::BinaryHeap;

fn main() {
    let mut pq = BinaryHeap::new();

    // Push elements
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    println!("Priority Queue (Max-Heap):");

    while let Some(val) = pq.pop() {
        println!("{}", val); // Elements come in descending order
    }
}
