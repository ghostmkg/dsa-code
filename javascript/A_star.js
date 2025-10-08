class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  toString() {
    return `${this.x},${this.y}`;
  }
}

// Manhattan distance heuristic
function heuristic(a, b) {
  return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
}

// Get valid neighbors in 4 directions
function getNeighbors(point, width, height) {
  const dirs = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
  ];
  const result = [];

  for (const [dx, dy] of dirs) {
    const nx = point.x + dx;
    const ny = point.y + dy;
    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
      result.push(new Point(nx, ny));
    }
  }

  return result;
}

// A* Algorithm
function aStar(start, goal, width, height, obstacles = []) {
  const obstacleSet = new Set(obstacles.map(o => o.toString()));

  const openSet = new Set([start.toString()]);
  const cameFrom = new Map();

  const gScore = new Map();
  const fScore = new Map();

  gScore.set(start.toString(), 0);
  fScore.set(start.toString(), heuristic(start, goal));

  while (openSet.size > 0) {
    // Get node with lowest fScore
    let currentKey = [...openSet].reduce((a, b) => {
      return (fScore.get(a) || Infinity) < (fScore.get(b) || Infinity) ? a : b;
    });

    const [cx, cy] = currentKey.split(',').map(Number);
    const current = new Point(cx, cy);

    if (current.toString() === goal.toString()) {
      // Reconstruct path
      const path = [current];
      let temp = current.toString();
      while (cameFrom.has(temp)) {
        temp = cameFrom.get(temp);
        const [px, py] = temp.split(',').map(Number);
        path.push(new Point(px, py));
      }
      return path.reverse();
    }

    openSet.delete(currentKey);

    for (const neighbor of getNeighbors(current, width, height)) {
      if (obstacleSet.has(neighbor.toString())) continue;

      const tentativeG = (gScore.get(currentKey) || Infinity) + 1;

      if (tentativeG < (gScore.get(neighbor.toString()) || Infinity)) {
        cameFrom.set(neighbor.toString(), currentKey);
        gScore.set(neighbor.toString(), tentativeG);
        fScore.set(neighbor.toString(), tentativeG + heuristic(neighbor, goal));
        openSet.add(neighbor.toString());
      }
    }
  }

  return null; // No path found
}

// Example usage
const width = 10;
const height = 10;
const start = new Point(0, 0);
const goal = new Point(7, 5);

const obstacles = [
  new Point(3, 1),
  new Point(3, 2),
  new Point(3, 3),
  new Point(3, 4),
];

const path = aStar(start, goal, width, height, obstacles);

if (path) {
  console.log("✅ Path found:");
  console.log(path.map(p => `(${p.x},${p.y})`).join(" → "));
} else {
  console.log("❌ No path found.");
}
