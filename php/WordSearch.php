<?php
/**
 * Simple Word Search in PHP (no class version)
 * Finds whether a given word exists in a 2D board.
 */

// Example board and word
$board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
];
$word = "ABCCED"; // Try changing this

// Function to check if the word exists in the board
function exist($board, $word) {
    $rows = count($board);
    $cols = count($board[0]);
    $visited = array_fill(0, $rows, array_fill(0, $cols, false));

    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            if (dfs($board, $word, $i, $j, 0, $visited, $rows, $cols)) {
                return true;
            }
        }
    }
    return false;
}

// DFS helper function
function dfs(&$board, $word, $i, $j, $index, &$visited, $rows, $cols) {
    if ($index === strlen($word)) {
        return true;
    }

    if ($i < 0 || $i >= $rows || $j < 0 || $j >= $cols) {
        return false;
    }

    if ($board[$i][$j] !== $word[$index] || $visited[$i][$j]) {
        return false;
    }

    $visited[$i][$j] = true;

    $found = (
        dfs($board, $word, $i + 1, $j, $index + 1, $visited, $rows, $cols) ||
        dfs($board, $word, $i - 1, $j, $index + 1, $visited, $rows, $cols) ||
        dfs($board, $word, $i, $j + 1, $index + 1, $visited, $rows, $cols) ||
        dfs($board, $word, $i, $j - 1, $index + 1, $visited, $rows, $cols)
    );

    $visited[$i][$j] = false;
    return $found;
}

// Run the function and print result
if (exist($board, $word)) {
    echo "Word '$word' exists in the board.\n";
} else {
    echo "Word '$word' does NOT exist in the board.\n";
}
