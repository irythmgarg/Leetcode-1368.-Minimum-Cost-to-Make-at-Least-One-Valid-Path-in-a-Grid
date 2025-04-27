# Leetcode-1368.-Minimum-Cost-to-Make-at-Least-One-Valid-Path-in-a-Grid
🚀 Minimum Cost to Make at Least One Valid Path in a Grid
Author: Ridham Garg
---

This repository contains two solutions to find the minimum cost required to reach the bottom-right corner of a grid starting from the top-left corner. The grid contains directional paths with specific costs, and the goal is to find the least costly valid path.

✨ Problem Statement
Given a grid with dimensions m x n, each cell contains an integer representing the cost of moving in a specific direction. The task is to find the minimum cost to travel from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1), where:

---

From each cell (i, j), you can move in one of four possible directions: up, down, left, or right.

The directions are specified by the value in the grid:

grid[i][j] = 1: Move right.

grid[i][j] = 2: Move left.

grid[i][j] = 3: Move down.

grid[i][j] = 4: Move up.

🧠 Approach 1: Depth First Search (DFS) with Backtracking
---
Overview
This approach uses Depth First Search (DFS) combined with backtracking to explore all possible paths in the grid while keeping track of the path costs. A key optimization is used to avoid unnecessary revisits using a visited matrix.

The algorithm recursively explores all four possible directions from each cell, adjusting the cost when the direction doesn't match the preferred one. Once the bottom-right corner is reached, it returns the minimum accumulated cost.

Time Complexity
Worst-case complexity: O(4^(m * n)), neighbors of every cell are checked.

---

🧠 Approach 2: Breadth First Search (BFS) with Priority Queue
---
Overview
This approach leverages Breadth First Search (BFS) along with a priority queue (min-heap) to explore the grid in layers, always expanding the least costly path first. Each move's cost is added to the queue with priority to explore paths that offer the lowest cost. This method guarantees that we find the minimum cost to reach the bottom-right corner efficiently.

Time Complexity
Worst-case complexity: O(m * n * log(m * n)), because each cell can be pushed and popped from the priority queue once.
