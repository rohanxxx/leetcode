class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currSum = max(nums[i], nums[i]+currSum);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};