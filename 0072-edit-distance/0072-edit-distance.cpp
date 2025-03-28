class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                int deleteOp = 1+dp[i-1][j];
                int insertOp = 1+dp[i][j-1];
                int replaceOp = 1+dp[i-1][j-1];
                dp[i][j] = min({deleteOp, insertOp, replaceOp});   
            }
        }
        // return func(n, m, s1, s2, dp);
        return dp[n][m];
    }
};