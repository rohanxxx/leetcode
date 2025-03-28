class Solution {
public:
    int func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = func(i-1, j-1, s1, s2, dp);
        }
        int deleteOp = 1+func(i-1, j, s1, s2, dp);
        int insertOp = 1+func(i, j-1, s1, s2, dp);
        int replaceOp = 1+func(i-1, j-1, s1, s2, dp);
        return dp[i][j] = min({deleteOp, insertOp, replaceOp});
    }
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(n, m, s1, s2, dp);
    }
};