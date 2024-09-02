class Solution {
public:
    
    int minCoinChange(vector<int>& coins, int rem, vector<int>& count){
        if(rem < 0) return -1;
        if(rem == 0) return 0;
        if(count[rem-1] != 0) return count[rem-1];
        
        int min = INT_MAX;
        for(int coin: coins){
            int res = minCoinChange(coins, rem-coin, count);
            if(res >= 0 && res < min) min = 1+res;
        }
        
        if(min == INT_MAX) count[rem-1] = -1;
        else count[rem-1] = min;
        
        return count[rem-1];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        vector<int> count(amount, 0);
        return minCoinChange(coins, amount, count);
    }

};