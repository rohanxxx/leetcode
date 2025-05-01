class Solution {
public:
/*                                          func(2)
                                    func(2)         
                                func(2) func(1)
                            func(2) func(1)  func(1) func(0)
*/
    int func(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(i < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int take = func(i, target-coins[i], coins, dp);
        int notTake = func(i-1, target, coins, dp);
        return dp[i][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};