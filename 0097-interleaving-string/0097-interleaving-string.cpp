class Solution {
public:
/* 
    s1 = aabb s2 = ccdd s3 = aebbccdd
*/
    bool func(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        if(i == s1.length() && j == s2.length()){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool ans = false;
        if(s1[i] == s3[k]) ans = ans || func(i+1, j, k+1, s1, s2, s3, dp);
        if(s2[j] == s3[k]) ans = ans || func(i, j+1, k+1, s1, s2, s3, dp);
        if(s1[i] != s3[k] && s2[j] != s3[k]){
            return false;
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();
        if(n+m > k) return false;
        if(n+m < k) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(0, 0, 0, s1, s2, s3, dp);
    }
};