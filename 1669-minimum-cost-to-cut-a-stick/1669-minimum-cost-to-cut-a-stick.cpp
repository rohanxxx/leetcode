class Solution {
public:
    int func(int i, int j, vector<int>& cuts, vector<vector<int>> dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int index = i; index <= j; index++){
            int cost = cuts[j+1]-cuts[i-1] + func(i, index-1, cuts, dp) + func(index+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        for(int i = c-2; i >= 1; i--){
            for(int j = 1; j <= c-2; j++){
                int mini = INT_MAX;
                for(int index = i; index <= j; index++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(cost, mini);
                }
                if(mini != INT_MAX){
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][cuts.size()-2];
    }
};