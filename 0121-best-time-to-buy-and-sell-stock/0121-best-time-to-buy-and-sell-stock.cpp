class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = prices[0], maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            maxProfit = max(maxProfit, prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        return maxProfit;
    }
};