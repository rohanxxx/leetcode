class Solution {
public:
    int func(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0 && obstacleGrid[i][j] != 1) return dp[i][j] = 1;
        if(i < 0 || j < 0) return 0;
        if(obstacleGrid[i][j] == 1) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up = func(obstacleGrid, i-1, j, dp);
        int left = func(obstacleGrid, i, j-1, dp);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0 && obstacleGrid[i][j] != 1){
                    dp[i][j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if(i - 1 >= 0) up = dp[i-1][j];
                if(j - 1 >= 0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        return dp[n-1][m-1];
    }
};