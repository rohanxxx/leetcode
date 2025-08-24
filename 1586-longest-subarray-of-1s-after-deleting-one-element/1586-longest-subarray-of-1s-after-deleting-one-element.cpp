class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxCount = 0;
        int prevCount = 0, curCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                curCount++;
            } 
            else { // nums[i] == 0
                if (i > 0 && nums[i - 1] == 0) {
                    prevCount = 0;
                } 
                else {
                    prevCount = curCount;
                }
                curCount = 0;
            }

            if (prevCount + curCount > maxCount) {
                maxCount = prevCount + curCount;
            }
        }

        if (maxCount == n) {
            return n - 1;
        } 
        else {
            return maxCount;
        }
    }
};