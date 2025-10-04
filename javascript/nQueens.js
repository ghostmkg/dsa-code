/**
 * N-Queens Problem
 * 
 * Description: Place N chess queens on an N×N chessboard so that no two queens
 * threaten each other. Uses backtracking to find all possible solutions.
 * 
 * Time Complexity: O(N!)
 * Space Complexity: O(N²)
 * 
 * Use Cases:
 * - Constraint satisfaction problems
 * - Resource allocation with conflicts
 * - Pattern generation and puzzle solving
 * - Algorithm education and demonstration
 * 
 * Example:
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
 */

function solveNQueens(n) {
    // Input validation
    if (!Number.isInteger(n) || n < 1) {
        throw new Error('Invalid input: n must be a positive integer');
    }

    const solutions = [];
    const board = Array.from({ length: n }, () => Array(n).fill('.'));
    const cols = new Set();
    const diag1 = new Set(); // row - col
    const diag2 = new Set(); // row + col

    function backtrack(row) {
        if (row === n) {
            solutions.push(board.map(r => r.join('')));
            return;
        }

        for (let col = 0; col < n; col++) {
            const d1 = row - col;
            const d2 = row + col;

            if (cols.has(col) || diag1.has(d1) || diag2.has(d2)) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';
            cols.add(col);
            diag1.add(d1);
            diag2.add(d2);

            backtrack(row + 1);

            // Remove queen (backtrack)
            board[row][col] = '.';
            cols.delete(col);
            diag1.delete(d1);
            diag2.delete(d2);
        }
    }

    backtrack(0);
    return solutions;
}

// Count total number of solutions
function totalNQueens(n) {
    let count = 0;
    const cols = new Set();
    const diag1 = new Set();
    const diag2 = new Set();

    function backtrack(row) {
        if (row === n) {
            count++;
            return;
        }

        for (let col = 0; col < n; col++) {
            const d1 = row - col;
            const d2 = row + col;

            if (cols.has(col) || diag1.has(d1) || diag2.has(d2)) {
                continue;
            }

            cols.add(col);
            diag1.add(d1);
            diag2.add(d2);

            backtrack(row + 1);

            cols.delete(col);
            diag1.delete(d1);
            diag2.delete(d2);
        }
    }

    backtrack(0);
    return count;
}

// Find first solution only (faster)
function findFirstSolution(n) {
    const board = Array.from({ length: n }, () => Array(n).fill('.'));
    const cols = new Set();
    const diag1 = new Set();
    const diag2 = new Set();

    function backtrack(row) {
        if (row === n) {
            return true;
        }

        for (let col = 0; col < n; col++) {
            const d1 = row - col;
            const d2 = row + col;

            if (cols.has(col) || diag1.has(d1) || diag2.has(d2)) {
                continue;
            }

            board[row][col] = 'Q';
            cols.add(col);
            diag1.add(d1);
            diag2.add(d2);

            if (backtrack(row + 1)) {
                return true;
            }

            board[row][col] = '.';
            cols.delete(col);
            diag1.delete(d1);
            diag2.delete(d2);
        }

        return false;
    }

    if (backtrack(0)) {
        return board.map(r => r.join(''));
    }
    return null;
}

// Visualize solution
function visualizeSolution(solution) {
    console.log('\n' + '='.repeat(solution[0].length * 4 + 1));
    for (let row of solution) {
        console.log('| ' + row.split('').join(' | ') + ' |');
        console.log('|' + '---+'.repeat(row.length).slice(0, -1) + '|');
    }
    console.log('='.repeat(solution[0].length * 4 + 1));
}

// Get queen positions as coordinates
function getQueenPositions(solution) {
    const positions = [];
    for (let row = 0; row < solution.length; row++) {
        for (let col = 0; col < solution[row].length; col++) {
            if (solution[row][col] === 'Q') {
                positions.push([row, col]);
            }
        }
    }
    return positions;
}

// Check if a configuration is valid
function isValidConfiguration(board) {
    const n = board.length;
    const queens = [];

    // Find all queens
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'Q') {
                queens.push([i, j]);
            }
        }
    }

    // Check all pairs
    for (let i = 0; i < queens.length; i++) {
        for (let j = i + 1; j < queens.length; j++) {
            const [r1, c1] = queens[i];
            const [r2, c2] = queens[j];

            // Same row, column, or diagonal
            if (r1 === r2 || c1 === c2 || 
                Math.abs(r1 - r2) === Math.abs(c1 - c2)) {
                return false;
            }
        }
    }

    return true;
}

// Optimized using bitmasking
function solveNQueensBitwise(n) {
    const solutions = [];
    const board = Array.from({ length: n }, () => Array(n).fill('.'));

    function backtrack(row, cols, diag1, diag2) {
        if (row === n) {
            solutions.push(board.map(r => r.join('')));
            return;
        }

        // Available positions (bits set to 1)
        let available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            const pos = available & -available; // Rightmost set bit
            const col = Math.log2(pos);
            
            board[row][col] = 'Q';
            backtrack(
                row + 1,
                cols | pos,
                (diag1 | pos) << 1,
                (diag2 | pos) >> 1
            );
            board[row][col] = '.';

            available &= available - 1; // Clear rightmost set bit
        }
    }

    backtrack(0, 0, 0, 0);
    return solutions;
}

// Performance comparison
function comparePerformance(n) {
    console.log(`\nSolving ${n}-Queens problem:\n`);

    console.time('Standard backtracking');
    const solutions1 = solveNQueens(n);
    console.timeEnd('Standard backtracking');

    console.time('Bitwise optimization');
    const solutions2 = solveNQueensBitwise(n);
    console.timeEnd('Bitwise optimization');

    console.log(`Total solutions: ${solutions1.length}`);
    console.log(`Solutions match: ${solutions1.length === solutions2.length}`);
}

// Test cases
console.log('4-Queens solutions:');
const solutions = solveNQueens(4);
solutions.forEach((solution, i) => {
    console.log(`\nSolution ${i + 1}:`);
    visualizeSolution(solution);
});

console.log('\nTotal 8-Queens solutions:', totalNQueens(8)); // 92

console.log('\nFirst solution for 8-Queens:');
const first = findFirstSolution(8);
if (first) visualizeSolution(first);

comparePerformance(10);

module.exports = { 
    solveNQueens, 
    totalNQueens, 
    findFirstSolution,
    visualizeSolution,
    getQueenPositions,
    isValidConfiguration,
    solveNQueensBitwise
};
