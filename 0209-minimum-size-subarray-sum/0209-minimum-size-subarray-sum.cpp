/*                      0 1 2 3 4 5
    target = 7, nums = [2,3,1,2,4,3]
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int curSum = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            curSum += nums[i];
            while(left <= i && curSum >= target){
                minLen = min(minLen, i-left+1);
                curSum -= nums[left++];
            }
        }

        if(minLen == INT_MAX){
            minLen = 0;
        }

        return minLen;
    }
};