class Solution {
public:
    bool dfs(int i, string& s, unordered_set<string>& set, vector<int>& dp){
        int n = s.length();
        if(i == n){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int res = false;
        for(int j = i; j < n; j++){
            //not exist skip
            if(set.find(s.substr(i, j-i+1)) == set.end()){
                continue;
            }
            res = res || dfs(j+1, s, set, dp);
        }

        return dp[i] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<int> dp(n+1, -1);
        return dfs(0, s, set, dp);
    }
};