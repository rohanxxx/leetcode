//m = 0, n = 1
class Solution {
public:
    int func(int index, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        //base case
        if(index == strs.size()) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];

        int take = 0, notTake = 0;
        int countM = m, countN = n;
        //TC: O(100)
        for(auto& c: strs[index]){
            if(c == '0') countM--;
            else countN--;
        }
        if(countM >= 0 && countN >= 0){
            take = 1 + func(index+1, strs, countM, countN, dp);
        }
        notTake = func(index+1, strs, m, n, dp);
        return dp[index][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return func(0, strs, m, n, dp);
    }
};