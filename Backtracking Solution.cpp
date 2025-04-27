// Author: [Ridham Garg]
// Problem: Minimum Cost to Make at Least One Valid Path in a Grid
// Approach: DFS with Cost Calculation

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Helper function to check if the (i, j) coordinates are valid within the grid
    bool isok(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // Recursive DFS function to find the minimum cost to reach bottom-right cell
    int nope(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited, int costtill) {
        
        // Base case: if we reach the bottom-right cell, return the accumulated cost
        if (i == m - 1 && j == n - 1)
            return costtill;
        
        visited[i][j] = 1; // Mark the current cell as visited
        
        // Directions: right, left, down, up
        vector<vector<int>> directions = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        
        int ans = 1e8; // Initialize the minimum cost to a large value

        // Try all 4 possible directions
        for (int p = 0; p <= 3; p++) {
            int newi = i + directions[p][0];
            int newj = j + directions[p][1];
            
            // Check if the new cell is within bounds and not visited
            if (isok(newi, newj, m, n) && visited[newi][newj] == false) {

                // If moving in the preferred direction (given by grid[i][j]), no extra cost
                // Otherwise, add 1 to the cost
                int cost = costtill + (grid[i][j] - 1 == p ? 0 : 1);

                // Recursively find the minimum cost
                ans = min(ans, nope(newi, newj, m, n, grid, visited, cost));
            }
        }
        
        visited[i][j] = false; // Backtrack: unmark the current cell
        return ans;
    }

    // Main function to find the minimum cost to reach the bottom-right corner
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize a visited matrix to keep track of the visited cells
        vector<vector<int>> visited(m, vector<int>(n, false));

        // Start DFS from the top-left corner with cost = 0
        return nope(0, 0, m, n, grid, visited, 0);
    }
};
