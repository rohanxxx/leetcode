class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double prefixSum = customers[0][0]+customers[0][1];
        double waitTime = customers[0][1];

        for(int i = 1; i < customers.size(); i++){
            // prefixSum += customers[i][1];
            prefixSum = max(double(customers[i][0]), prefixSum)+customers[i][1];
            waitTime += (prefixSum-customers[i][0]);
        }
        double avgTime = waitTime/customers.size();
        return avgTime;
    }
};