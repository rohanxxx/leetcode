class Solution {
public:
    int func(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(r == 0 && c == 0 && matrix[r][c] != 1) return 1;
        if(r < 0 || c < 0) return 0;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        if(matrix[r][c] == 1) return 0;
        
        int upPath = func(r-1, c, matrix, dp);
        int leftPath = func(r, c-1, matrix, dp);
        
        return dp[r][c] = upPath+leftPath; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(r == 0 && c == 0 && obstacleGrid[r][c] != 1) {
                    dp[r][c] = 1;
                    continue;
                }
                if(obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0; 
                    continue;
                }
                int up = 0, left = 0;
                if(r-1 >= 0) up = dp[r-1][c];
                if(c-1 >= 0) left = dp[r][c-1];
                dp[r][c] = up + left;
            }
        }
        return dp[n-1][m-1];
    }
};