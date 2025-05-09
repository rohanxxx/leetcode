/*
    the gas tank can take unlimited gas
    give cost[i] container and the cost from ith to to i+1th station (gas and cost)
    begin the journey with an empty tank

    return the starting gas stations index if you can travel around the circuit once in the clockwise direction (right)

    Input: gas = [1,2,3,4,5] 
        cost =   [3,4,5,1,2]
                  0 1 2 3 4
    Output: 3
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGain = 0, totalGain = 0, answer = 0;

        for (int i = 0; i < gas.size(); ++i) {
            // gain[i] = gas[i] - cost[i]
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];

            // If we meet a "valley", start over from the next station
            // with 0 initial gas.
            if (currGain < 0) {
                answer = i + 1;
                currGain = 0;
            }
        }

        return totalGain >= 0 ? answer : -1;
    }
};