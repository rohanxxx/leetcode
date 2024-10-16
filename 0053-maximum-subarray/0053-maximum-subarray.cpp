class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(auto num: nums){
            currSum = max(num, currSum+num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};