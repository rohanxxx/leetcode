class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int minCost = 0;
        int right = cost.size()-1;

        sort(cost.begin(), cost.end());
        while(right > -1 && right != 0 && right != 1){
            minCost += (cost[right] + cost[right-1]);
            right -= 3;
        }
        if(right == 0){
            minCost += cost[0];
        }
        if(right == 1){
            minCost += cost[0]+cost[1];
        }
        return minCost;
    }
};