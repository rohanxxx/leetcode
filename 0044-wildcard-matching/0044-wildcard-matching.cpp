class Solution {
public:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return true;
        if(i > 0  && j == 0) return false;
        if(i == 0 && j > 0){
            while(j){
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j-1] == '*'){
            return dp[i][j] = dfs(i, j-1, s, p, dp) || dfs(i-1, j, s, p, dp);
        }
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = dfs(i-1, j-1, s, p, dp);
        } 

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int j = 1; j <= m; j++) {
            bool flag = true;

            for(int jj = 1; jj <= j; jj++) {
                if(p[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[0][j] = flag;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};