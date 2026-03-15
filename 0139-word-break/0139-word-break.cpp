class Solution {
public:
    bool dfs(int i, string cur, string& s, unordered_set<string>& set,
             unordered_map<string, int>& dp) {
        int n = (int)s.length();

        if (i < n) {
            cur.push_back(s[i]);
        }

        // base case
        if (i == n) {
            return set.find(cur) != set.end();
        }

        string key = to_string(i) + "#" + cur;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        bool take = false, notTake = false;

        if (set.find(cur) != set.end()) {
            take = dfs(i + 1, "", s, set, dp);
        }

        notTake = dfs(i + 1, cur, s, set, dp);

        return dp[key] = (take || notTake);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        unordered_map<string, int> dp;
        return dfs(0, "", s, set, dp);
    }
};