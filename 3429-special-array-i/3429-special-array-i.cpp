class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        //tc: O(N-1)
        for(int i = 1; i < n; i++){
            if(nums[i-1]%2 == nums[i]%2) return false;
        }
        return true;
    }
};