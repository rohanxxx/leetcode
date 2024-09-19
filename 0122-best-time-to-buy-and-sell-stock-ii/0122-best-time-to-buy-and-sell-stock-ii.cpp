class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff, profit = 0;
        for(int i = 1; i < prices.size(); i++){
            diff = prices[i-1] - prices[i];
            if(diff < 1){
                profit += (diff*-1);
            }
        }
        return profit;
    }
};