class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minSubLen = INT_MAX, sumCurrWindow = 0;

        for(right; right < nums.size(); right++){
            sumCurrWindow += nums[right];
            while(target <= sumCurrWindow){
                minSubLen = min(minSubLen, right-left+1);
                sumCurrWindow -= nums[left];
                left++;
            }
        }

        if (minSubLen == INT_MAX) return 0;
        return minSubLen;
    }
};