class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = INT_MAX, left = INT_MAX;
                if(i-1 >= 0) up = dp[i-1][j];
                if(j-1 >= 0) left = dp[i][j-1];
                int mini = min(up, left);
                dp[i][j] = grid[i][j] + mini;
            }
        }
        return dp[n-1][m-1];
    }
};