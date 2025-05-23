class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    long profit = 0;
                    int sell = 0, notSell = 0;
                    if(buy){
                        sell = ahead[0][cap] - prices[i];
                        notSell = ahead[1][cap];
                    }
                    else{
                        sell = prices[i] + ahead[1][cap-1];
                        notSell = ahead[0][cap];
                    }
                    profit = max(sell, notSell);
                    ahead[buy][cap] = profit;
                }
            }
        }
        return ahead[1][k];
    }
};