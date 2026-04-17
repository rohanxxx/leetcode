/*
    target = 7, 
            0 1 2 3 4 5
    nums = [2,3,1,2,4,3]
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        int left = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(left <= i && sum >= target){
                minLen = min(minLen, i-left+1);
                sum-= nums[left];
                left++;
            }
        }
        if(minLen == INT_MAX){
            return 0;
        }
        return minLen;
    }
};