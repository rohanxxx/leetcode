class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double sum = 0.0;
        
        for(int i = 0; i < k; i++) 
            sum += (double)nums[i];
        maxAvg = max(maxAvg, (double)sum/(double)k);
        
        for(int i = k; i < nums.size(); i++){
            sum += (double)nums[i];
            sum -= (double)nums[i-k];
            maxAvg = max(maxAvg, (double)sum/(double)k);
        }
        
        return maxAvg;
    }
};