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

        bool res = false;
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
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dfs(n, m, s, p, dp);
    }
};