class Solution {
public:
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