#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Solution for LeetCode 778: Swim in Rising Water.
 * * This problem asks for the minimum 'time' t such that a path exists from (0, 0)
 * to (N-1, N-1), where all cells on the path have an elevation <= t.
 * This is equivalent to finding the path with the minimum bottleneck capacity, 
 * which is solved efficiently using Dijkstra's algorithm.
 */
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int N = grid.size();
        
        // Priority Queue for Dijkstra's Algorithm:
        // Stores {max_elevation_so_far, row, col}.
        // We use std::greater to create a Min-Heap. The priority queue always 
        // retrieves the unvisited cell that has the smallest current required max elevation (time).
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // dist[r][c] stores the minimum time (max elevation) required to reach cell (r, c).
        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

        // Start at (0, 0). The required time to be at (0, 0) is at least its elevation.
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        // Directions for movement: Right, Left, Down, Up
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            // Get the cell with the smallest required maximum elevation so far.
            auto [time, r, c] = pq.top();
            pq.pop();

            // Optimization: If a path with a lower or equal time has already 
            // been processed, skip this one.
            if (time > dist[r][c]) {
                continue;
            }

            // Target check: If we reached the end, return the time.
            if (r == N - 1 && c == N - 1) {
                return time;
            }

            // Explore neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundary conditions
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    
                    // The time required to enter the new cell (nr, nc) is the 
                    // maximum of the current path's required time (time) and the 
                    // elevation of the destination cell (grid[nr][nc]).
                    int new_time = max(time, grid[nr][nc]);

                    // Relaxation step: If we found a path with a better (smaller) 
                    // maximum elevation, update the distance and push it to the queue.
                    if (new_time < dist[nr][nc]) {
                        dist[nr][nc] = new_time;
                        pq.push({new_time, nr, nc});
                    }
                }
            }
        }

        // The problem guarantees a path exists, so this return should ideally not be reached.
        return dist[N - 1][N - 1]; 
    }
};
