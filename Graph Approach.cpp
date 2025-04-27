// Author: [Ridham Garg]
// Problem: Minimum Cost to Make at Least One Valid Path in a Grid
// Approach: Dijkstra's Algorithm (Priority Queue) for finding minimum cost path

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:

    // Helper function to check if the (i, j) coordinates are valid within the grid
    bool isok(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // Main function to find the minimum cost to reach the bottom-right corner using Dijkstra's Algorithm
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        // Initialize a visited matrix to store the minimum cost for each cell
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

        // Priority queue to store the cells being processed, sorted by cost
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Start from the top-left corner (0, 0) with a cost of 0
        pq.push({0, {0, 0}});
        visited[0][0] = 0;

        // Directions for moving right, left, down, and up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Process the grid using Dijkstra's algorithm
        while (!pq.empty()) {
            // Get the cell with the least cost
            auto top = pq.top();
            pq.pop();
            int i = top.second.first; // Current row
            int j = top.second.second; // Current column
            int cost = top.first; // Current cost to reach (i, j)

            // Check all 4 possible directions
            for (int p = 0; p <= 3; p++) {
                // Calculate the new cell's coordinates
                int newi = i + directions[p][0];
                int newj = j + directions[p][1];

                // If the new cell is out of bounds, skip it
                if (!isok(newi, newj, m, n))
                    continue;

                // Calculate the new cost to reach (newi, newj)
                int newcost = cost + (grid[i][j] - 1 == p ? 0 : 1);

                // If the new cost is less than the previously recorded cost, update and add to the priority queue
                if (newcost < visited[newi][newj]) {
                    visited[newi][newj] = newcost;
                    pq.push({newcost, {newi, newj}});
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner (m-1, n-1)
        return visited[m - 1][n - 1];
    }
};
