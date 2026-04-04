class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i/coins[0];
            }
            else{
                prev[i] = INT_MAX;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int take = INT_MAX;
                int notTake = prev[j];
                if(j >= coins[i]){
                    take = curr[j-coins[i]];
                    if(take != INT_MAX){
                        take++;
                    }
                }
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }
        if(prev[amount] == INT_MAX){
            return -1;
        }
        return prev[amount];
    }
};