class Solution {
public:
    int dfs(int i, const int& n, string& s, vector<int>& dp){
        if(s[i] == '0'){
            return 0;
        }
        if(i >= n-1){
            return 1;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        int singleDigit = s[i]-'0';
        int doubleDigit = singleDigit*10+(s[i+1]-'0');
        
        int count = 0;
        
        count += dfs(i+1, n, s, dp);
        
        if(doubleDigit <= 26){
            //for double digit case
            count += dfs(i+2, n, s, dp);
        }
        return dp[i] = count;
    }
    int numDecodings(string s) {
        int n = (int)s.length();
        vector<int> dp(n, INT_MIN);
        return dfs(0, n, s, dp);
    }
};