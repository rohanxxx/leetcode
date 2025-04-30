class Solution {
public:
    int solve(int i, string& s, vector<int>& dp){
        if(s[i] == '0') return 0;
        if(i >= s.length()-1) return 1;
        
        if(dp[i] != -1) return dp[i];

        int ans = solve(i+1, s, dp);
        
        if(stoi(s.substr(i, 2)) <= 26) {
            ans += solve(i+2, s, dp);
        }
    
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);
    }
};