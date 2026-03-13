/*
    [7,1,5,3,6,4]
    7x, > 1, 3, 6

    5-1 -> 4, 6-3 = 3, 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevPick = prices[0], sum = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prevPick){
                //cout << "prices[i]: " << prices[i] << endl;
                sum += (prices[i]-prevPick);
            }
            prevPick = prices[i];
        }
        return sum;
    }
};