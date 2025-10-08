use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

// A point on the grid
#[derive(Clone, Copy, Eq, PartialEq, Hash, Debug)]
struct Point {
    x: i32,
    y: i32,
}

// Node with cost info for A*
#[derive(Clone, Eq, PartialEq)]
struct Node {
    position: Point,
    cost: i32,     // g(n): cost from start to this node
    priority: i32, // f(n) = g(n) + h(n)
}

// Implement ordering so BinaryHeap pops lowest f(n)
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.priority.cmp(&self.priority)
            .then_with(|| self.cost.cmp(&other.cost))
    }
}
impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Heuristic function: Manhattan distance
fn heuristic(a: Point, b: Point) -> i32 {
    (a.x - b.x).abs() + (a.y - b.y).abs()
}

// Get all valid neighboring points
fn neighbors(p: Point, width: i32, height: i32) -> Vec<Point> {
    let mut result = Vec::new();
    let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];
    for (dx, dy) in directions {
        let nx = p.x + dx;
        let ny = p.y + dy;
        if nx >= 0 && nx < width && ny >= 0 && ny < height {
            result.push(Point { x: nx, y: ny });
        }
    }
    result
}

// A* search function
fn astar(
    start: Point,
    goal: Point,
    width: i32,
    height: i32,
    obstacles: &Vec<Point>,
) -> Option<Vec<Point>> {
    let mut open_set = BinaryHeap::new();
    open_set.push(Node {
        position: start,
        cost: 0,
        priority: heuristic(start, goal),
    });

    let mut came_from: HashMap<Point, Point> = HashMap::new();
    let mut cost_so_far: HashMap<Point, i32> = HashMap::new();
    cost_so_far.insert(start, 0);

    while let Some(current) = open_set.pop() {
        if current.position == goal {
            // Reconstruct path
            let mut path = vec![goal];
            let mut current = goal;
            while let Some(&prev) = came_from.get(&current) {
                path.push(prev);
                current = prev;
            }
            path.reverse();
            return Some(path);
        }

        for next in neighbors(current.position, width, height) {
            if obstacles.contains(&next) {
                continue; // skip obstacles
            }

            let new_cost = cost_so_far[&current.position] + 1;
            if !cost_so_far.contains_key(&next) || new_cost < cost_so_far[&next] {
                cost_so_far.insert(next, new_cost);
                let priority = new_cost + heuristic(next, goal);
                open_set.push(Node {
                    position: next,
                    cost: new_cost,
                    priority,
                });
                came_from.insert(next, current.position);
            }
        }
    }

    None // no path found
}

fn main() {
    let width = 10;
    let height = 10;

    let start = Point { x: 0, y: 0 };
    let goal = Point { x: 7, y: 5 };

    let obstacles = vec![
        Point { x: 3, y: 1 },
        Point { x: 3, y: 2 },
        Point { x: 3, y: 3 },
        Point { x: 3, y: 4 },
    ];

    match astar(start, goal, width, height, &obstacles) {
        Some(path) => {
            println!("Path found:");
            for p in path {
                print!("({},{}) ", p.x, p.y);
            }
            println!();
        }
        None => println!("No path found."),
    }
}
