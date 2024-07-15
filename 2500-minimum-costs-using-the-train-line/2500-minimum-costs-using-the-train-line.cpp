class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int size = regular.size()+1;
        
        long prevRegularLaneCost = 0;
        long prevExpressLaneCost = expressCost;
        vector<long long> minCost;

        for(int i = 1; i < size; i++){
            long regLaneCost = regular[i-1]+min(prevRegularLaneCost, prevExpressLaneCost);
            long regExpressLaneCost = express[i-1]+min(expressCost+prevRegularLaneCost, prevExpressLaneCost);
            
            minCost.push_back(min(regLaneCost, regExpressLaneCost));
            
            prevRegularLaneCost = regLaneCost;
            prevExpressLaneCost = regExpressLaneCost;
        }
        return minCost;
    }
};