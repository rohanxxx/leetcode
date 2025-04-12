class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1+func(i, j-1, dp) + func(i-1, j, dp);
    }
    int uniquePaths(int m, int n) {
        if(m == 1 and n == 1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m-1, n-1, dp)+1;
    }
};