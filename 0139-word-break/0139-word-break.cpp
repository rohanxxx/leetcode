class Solution {
public:
    bool dfs(int i, const int& n, string& s, vector<string>& wordDict, vector<int>& dp){
        if(i == n){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        bool result = false;
        for(auto word: wordDict){
            int k = word.size();
            if(i+k-1 < n && s.substr(i, k) == word){
                result = (result || dfs(i+k, n, s, wordDict, dp));
            }
        }
        return dp[i] = result;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;//base case
        for(int i = n-1; i >= 0; i--){
            bool result = false;
            for(auto word: wordDict){
                int k = word.size();
                if(i+k-1 < n && s.substr(i, k) == word){
                    result = (result || dp[i+k]);
                }
            }
            dp[i] = result;
        }
        return dp[0];
    }
};