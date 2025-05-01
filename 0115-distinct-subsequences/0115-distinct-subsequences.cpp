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
        if(j == t.length()){
            return 1;
        }
        if(j < t.length() && i == s.length()){
            return 0;
        }
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
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(0, 0, s, t, dp);
    }
};