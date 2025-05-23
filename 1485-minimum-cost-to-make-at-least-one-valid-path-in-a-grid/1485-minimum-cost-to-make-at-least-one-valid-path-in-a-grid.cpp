/*
    problem is requiring me to traverese from top left to bottom right means
    0,0 -> n-1, m-1
    1 -> right 2 -> left 3 -> down 4 -> up
    we can only change one cell at cost of 1 only one cell can be modified only once

    final answer: return the minimum cost to make the grid have a t least one valid path
    Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    Output: 3

    [1,1,1,1]
    [2,2,2,2]
    [1,1,1,1]
    [2,2,2,2]

    Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
    Output: 0

    [1,1,3]
    [3,2,2]
    [1,1,4]
    output = 0;

    [1,1,3]
    [2,2,2]
    [4,4,1]
*/

class Solution {
private:
    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), cost = 0;

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Queue for BFS part - stores cells that need cost increment
        queue<pair<int, int>> queue;

        // Start DFS from origin with cost 0
        dfs(grid, 0, 0, minCost, cost, queue);

        // BFS part - process cells level by level with increasing cost
        while (!queue.empty()) {
            cost++;
            int levelSize = queue.size();

            while (levelSize-- > 0) {
                auto [row, col] = queue.front();
                queue.pop();

                // Try all 4 directions for next level
                for (int dir = 0; dir < 4; dir++) {
                    dfs(grid, row + dirs[dir][0], col + dirs[dir][1], minCost,
                        cost, queue);
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // DFS to explore all reachable cells with current cost
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& minCost, int cost,
             queue<pair<int, int>>& queue) {
        if (!isUnvisited(minCost, row, col)) return;

        minCost[row][col] = cost;
        queue.push({row, col});

        // Follow the arrow direction without cost increase
        int nextDir = grid[row][col] - 1;
        dfs(grid, row + dirs[nextDir][0], col + dirs[nextDir][1], minCost, cost,
            queue);
    }

    // Check if cell is within bounds and unvisited
    bool isUnvisited(vector<vector<int>>& minCost, int row, int col) {
        return row >= 0 && col >= 0 && row < minCost.size() &&
               col < minCost[0].size() && minCost[row][col] == INT_MAX;
    }
};