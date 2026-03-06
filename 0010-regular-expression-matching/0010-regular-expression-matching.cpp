class Solution {
public:
    bool func(int i, int j, string& s, string &p, vector<vector<int>>& dp){
        int n = s.length();
        int m = p.length();

        // CHANGE 1: correct base case
        if(j == m) return i == n;

        if(dp[i][j] != -1) return dp[i][j];

        // CHANGE 2: only match if i is valid
        bool take = false;
        bool notTake = false;
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));

        // CHANGE 3: '*' is not checked at p[j], it modifies p[j]
        // so we check whether next char is '*'
        if(j + 1 < m && p[j + 1] == '*'){
            // CHANGE 4: skip current char + '*'
            notTake = func(i, j + 2, s, p, dp);

            // CHANGE 5: use current char if it matches
            if(match){
                take = func(i + 1, j, s, p, dp);
            }
        }
        else{
            // CHANGE 6: normal single character match
            if(match){
                take = func(i + 1, j + 1, s, p, dp);
            }
        }

        return dp[i][j] = take || notTake;
    }

    bool isMatch(string s, string p) {
        // CHANGE 7: removed invalid edge case if(p[0] == '*')
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(0, 0, s, p, dp);
    }
};