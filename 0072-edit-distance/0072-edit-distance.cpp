class Solution {
public:
    int dfs(int i, int j, string& w1, string& w2, vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;

        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i-1] == w2[j-1]){
            return dp[i][j] = dfs(i-1, j-1, w1, w2, dp);
        }

        int del = 1 + dfs(i, j-1, w1, w2, dp);
        int ins = 1 + dfs(i-1, j, w1, w2, dp);
        int rep = 1 + dfs(i-1, j-1, w1, w2, dp);

        return dp[i][j] = min({del, ins, rep});
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //for(int i = 0; i <= n; i++) dp[i][0] = i;
        //for(int j = 0; j <= m; j++) dp[0][j] = j;
        vector<int> prev(m+1, 0), cur(m+1, 0);
        for(int j = 0; j <= m; j++) prev[j] = j;
        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                if(w1[i-1] == w2[j-1]){
                    cur[j] = prev[j-1];
                    continue;
                }

                int del = 1 + prev[j];
                int ins = 1 + cur[j-1];
                int rep = 1 + prev[j-1];

                cur[j] = min({del, ins, rep});
            }
            prev = cur;
        }
        return prev[m];
    }
};