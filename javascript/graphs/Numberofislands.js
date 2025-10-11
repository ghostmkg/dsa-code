class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    numIslands(grid) {
        const directions = [
            [1, 0],
            [-1, 0],
            [0, 1],
            [0, -1],
        ];
        const ROWS = grid.length,
            COLS = grid[0].length;
        let islands = 0;

        const dfs = (r, c) => {
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] === '0')
                return;

            grid[r][c] = '0';
            for (const [dr, dc] of directions) {
                dfs(r + dr, c + dc);
            }
        };

        for (let r = 0; r < ROWS; r++) {
            for (let c = 0; c < COLS; c++) {
                if (grid[r][c] === '1') {
                    dfs(r, c);
                    islands++;
                }
            }
        }

        return islands;
    }
}