/*
    ["0","E","0","0"]
    ["E","0","W","E"]
    ["0","E","0","0"]
    expected = 3

    ["W","W","W"]
    ["0","0","0"]
    ["E","E","E"]
    expected 1
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int maxCount = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '0') {
                    int hits = killEnemies(row, col, grid);
                    maxCount = max(maxCount, hits);
                }
            }
        }

        return maxCount;
    }

private:
    int killEnemies(int row, int col, vector<vector<char>>& grid) {
        int enemyCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Look left
        for (int c = col - 1; c >= 0; --c) {
            if (grid[row][c] == 'W') break;
            if (grid[row][c] == 'E') enemyCount++;
        }

        // Look right
        for (int c = col + 1; c < cols; ++c) {
            if (grid[row][c] == 'W') break;
            if (grid[row][c] == 'E') enemyCount++;
        }

        // Look up
        for (int r = row - 1; r >= 0; --r) {
            if (grid[r][col] == 'W') break;
            if (grid[r][col] == 'E') enemyCount++;
        }

        // Look down
        for (int r = row + 1; r < rows; ++r) {
            if (grid[r][col] == 'W') break;
            if (grid[r][col] == 'E') enemyCount++;
        }

        return enemyCount;
    }
};