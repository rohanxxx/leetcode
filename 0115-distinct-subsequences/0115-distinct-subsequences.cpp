class Solution {
    /*
        rabbbit         rabbit
        0123456         0123456
        
        0123 56
        01 3456
        012 456
    */
public:
    //O(2^n*m) imporove it to O(n*m)
    int func(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j == t.length()) return 1;
        if(j < t.length() && i == s.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int matched = 0;
        if(s[i] == t[j]){
            matched = func(i+1, j+1, s, t, dp);
        }
        int regardless = func(i+1, j, s, t, dp);
        return dp[i][j] = matched+regardless;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        /*for(int j = 0; j <= m; j++){
            dp[n][j] = 0;
        }*/
        for(int i = 0; i <= n; i++){
            dp[i][m] = 1;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int matched = 0;
                if(s[i] == t[j]){
                    matched = dp[i+1][j+1];
                }
                int regardless = dp[i+1][j];
                dp[i][j] = (long long)matched+regardless;
            }
        }
        return dp[0][0];
    }
};