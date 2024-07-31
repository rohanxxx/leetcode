class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> prefix, result;
        prefix.push_back(nums[0]);

        int n = nums.size();
        for(int i = 1; i < n; i++){
            prefix.push_back(prefix[i-1]+nums[i]);
        }

        for(int i = 0; i < n; i++){
            int leftSum = abs(prefix[i]- abs(nums[i]*(i+1)));
            int rightSum = abs(prefix[n-1]-prefix[i] - abs(nums[i]*(n-1-i)));
            result.push_back(leftSum+rightSum);
        }

        return result;
    }
};