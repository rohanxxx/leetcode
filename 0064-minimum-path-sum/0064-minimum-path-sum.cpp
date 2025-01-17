class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int> dp(row, vector<int>(col, 0));
        
        dp[0][0] = grid[0][0];
        for(int c = 1; c < col; c++){
            dp[0][c] = dp[0][c-1]+grid[0][c];
        }
        for(int r = 1; r < row; r++){
            dp[r][0] += dp[r-1][0]+grid[r][0];
        }

        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c];
            }
        }

        return dp[row-1][col-1];
    }
};