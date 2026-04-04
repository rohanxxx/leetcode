class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp){
        if(i == 1 && j == 1){
            return 1;
        }
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int r1 = dfs(i-1, j, dp);
        int r2 = dfs(i, j-1, dp);
        return dp[i][j] = r1+r2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1){
                    continue;
                }
                int r1 = dp[i-1][j];
                int r2 = dp[i][j-1];
                dp[i][j] = r1+r2;
            }
        }
        return dp[m][n];
    }
};