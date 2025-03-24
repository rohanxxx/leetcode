class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i == 0 && j == 0) return dp[i][j] = grid[i][j];
        if(i < 0 || i >= n || j < 0 || j >= m){
            return INT_MAX;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int up = func(i-1, j, grid, dp);
        // int down = func(i+1, j, grid, dp);
        int left = func(i, j-1, grid, dp);
        // int right = func(i, j+1, grid, dp);

        int mini = min(up, left);
        if(mini == INT_MAX) mini = 0;
        return dp[i][j] = (grid[i][j] + mini);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n-1, m-1, grid, dp);
    }
};