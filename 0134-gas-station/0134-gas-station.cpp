/*
 gas = [1, 2, 3, 4,5], cost = [3,4,5,1,2]
       -2,-4,-6,-3,0
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGain = 0, currGain = 0, n = gas.size();

        int startIndex = 0;
        for(int i = 0; i < n; i++){
            currGain += (gas[i]-cost[i]);
            totalGain += (gas[i]-cost[i]);
            if(currGain < 0){
                startIndex = i+1;
                currGain = 0;
            }
            
        }
        if(totalGain >= 0){
            return startIndex;
        }
        return -1;
    }
};