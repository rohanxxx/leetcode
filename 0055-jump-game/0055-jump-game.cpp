/*
                   0 1 2 3 4
    Input: nums = [3,2,1,0,4]
    Output: false
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = nums[0];
        for(int i = 1; i < n; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, i+nums[i]);
        }
        return true;
    }
};