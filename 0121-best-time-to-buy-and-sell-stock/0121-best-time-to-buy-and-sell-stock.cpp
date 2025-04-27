class Solution {
public:
    /*
       [7,        1,5,3,6,4]
       [INT_MAX,  7,1,1,1,1]
       [-INT_MIN,-6,4,2,5,3] 
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int leftMin = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            int curProfit = prices[i]-leftMin;
            maxProfit = max(maxProfit, curProfit);
            leftMin = min(leftMin, prices[i]);
        }
        return maxProfit;
    }
};