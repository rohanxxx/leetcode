class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i < 0 || j < 0){
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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m-1, n-1, dp);
    }
};