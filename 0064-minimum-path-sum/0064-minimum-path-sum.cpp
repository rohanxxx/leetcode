class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int columnSize = grid[0].size();
        vector<vector<int>> dp(rowSize, vector<int>(columnSize, 0));
        
        dp[rowSize-1][columnSize-1] = grid[rowSize-1][columnSize-1];
        for(int c = columnSize-2; c >= 0; c--){
            dp[rowSize-1][c] = dp[rowSize-1][c+1] + grid[rowSize-1][c];
        }
        for(int r = rowSize-2; r >= 0; r--){
            dp[r][columnSize-1] = dp[r+1][columnSize-1] + grid[r][columnSize-1];
        }

        for(int r = rowSize-2; r >= 0; r--){
            for(int c = columnSize-2; c >= 0; c--){
                int rightSum = dp[r][c+1];
                int downSum = dp[r+1][c];
                dp[r][c] = min(rightSum, downSum)+grid[r][c];
            }
        }
        return dp[0][0];
    }
};