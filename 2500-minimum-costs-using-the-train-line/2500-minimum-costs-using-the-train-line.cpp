class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int size = regular.size();
        
        long prevRegularLaneCost = 0;
        long prevExpressLaneCost = expressCost;
        vector<long long> minCost;

        for(int i = 0; i < size; i++){
            long regLaneCost = regular[i]+min(prevRegularLaneCost, prevExpressLaneCost);
            long regExpressLaneCost = express[i]+min(expressCost+prevRegularLaneCost, prevExpressLaneCost);
            
            minCost.push_back(min(regLaneCost, regExpressLaneCost));
            
            prevRegularLaneCost = regLaneCost;
            prevExpressLaneCost = regExpressLaneCost;
        }
        return minCost;
    }
};