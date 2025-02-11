class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp0, dp1;
        dp0.push_back(nums[0]);
        dp0.push_back(max(nums[1], nums[0]));

        for(int i = 0; i < len-1; i++){
            int size = dp0.size();
            dp0.push_back(max(dp0[size-1], dp0[size-2]+nums[i]));
        }

        dp1.push_back(nums[1]);
        dp1.push_back(max(nums[1], nums[2]));

        for(int i = 1; i < len; i++){
            int size = dp1.size();
            dp1.push_back(max(dp1[size-1], dp1[size-2]+nums[i]));
        }

        return max(dp1.back(), dp0.back());
    }
};