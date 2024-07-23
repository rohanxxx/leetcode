class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double prefixSum = customers[0][0]+customers[0][1];
        cout << "prefixSum: " << prefixSum << endl;
        double waitTime = customers[0][1];
        cout << "waitTime: " << waitTime << endl;
        for(int i = 1; i < customers.size(); i++){
            // prefixSum += customers[i][1];
            prefixSum = max(double(customers[i][0]), prefixSum)+customers[i][1];
            cout << "prefixSum: " << prefixSum << endl;
            waitTime += (prefixSum-customers[i][0]);
            cout << "waitTime: " << waitTime << endl;
        }
        cout << "waitTime: " << waitTime << endl;
        double avgTime = waitTime/customers.size();
        return avgTime;
    }
};