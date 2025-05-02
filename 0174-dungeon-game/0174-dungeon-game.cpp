class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        // Initialize the DP table with INT_MAX
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        
        // Iterate from bottom-right to top-left
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                int currCell = dungeon[row][col];
                int min_health;

                cout << "row: " << row << " col: " << col << endl;
                if (row == rows - 1 && col == cols - 1) {
                    // Base case: bottom-right cell (princess location)
                    if (currCell >= 0) {
                        min_health = 1;
                    } else {
                        min_health = 1 - currCell;
                    }
                } else {
                    int right = INT_MAX;
                    int down = INT_MAX;

                    // Check right cell
                    if (col + 1 < cols) {
                        right = dp[row][col + 1];
                    }

                    // Check down cell
                    if (row + 1 < rows) {
                        down = dp[row + 1][col];
                    }
                    //cout << "right: " << right << " down: " << down << endl; 
                    int next_health = min(right, down);
                    int required = next_health - currCell;

                    if (required <= 0) {
                        min_health = 1;
                    } else {
                        min_health = required;
                    }
                }
                cout << "min_health: " << min_health << endl << endl;
                dp[row][col] = min_health;
            }
        }

        return dp[0][0];
    }
};