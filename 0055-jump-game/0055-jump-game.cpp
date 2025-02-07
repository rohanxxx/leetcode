class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0, size = nums.size();
        if(nums.size() == 1) return true;
        for(int i = 0; i < size-1; i++){
            if(nums[i] == 0) continue;
            if(i <= maxLen){
                maxLen = max(maxLen, i+nums[i]);
            }
            if(maxLen >= size-1){
                return true;
            }
        }
        return false;
    }
};