class Solution {
public:
    int func(int i, int j, string& s, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            if(i == j) return dp[i][j] = 1 + func(i+1, j-1, s, dp);
            else return dp[i][j] = 2+func(i+1, j-1, s, dp);
        }
        return dp[i][j] = max(func(i, j-1, s, dp), func(i+1, j, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, n-1, s, dp);
    }
};