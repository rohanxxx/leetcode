class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOnes = 0;
        int consecutiveOne = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) consecutiveOne++;
            else consecutiveOne = 0;
            maxOnes = max(maxOnes, consecutiveOne);
        }
        return maxOnes;
    }
};