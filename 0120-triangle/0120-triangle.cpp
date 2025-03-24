class Solution {
public:
    int func(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp){
        if(i == 0 && j == 0) {
            return dp[i][j] = t[i][j];
        }
        if(j < 0 || j == t[i].size()){
            return INT_MAX;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int left = func(i-1, j-1, t, dp);
        int right = func(i-1, j, t, dp);
        int mini = min(left, right);
        
        return dp[i][j] = (t[i][j]+mini);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 1; i <= m; i++){
            mini = min(mini, func(n-1, m-i, triangle, dp));
        }
        return mini;
    }
};