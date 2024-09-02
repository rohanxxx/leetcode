class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> sum(n);
        
        sum[0] = nums[0];
        sum[1] = max(nums[1], nums[0]);
        
        int tempMaxSum = max(sum[0], sum[1]);

        for(int i = 2; i < n; i++){
            sum[i] = max(nums[i]+sum[i-2], tempMaxSum);
            tempMaxSum = sum[i];
        }

        return sum[n-1];
    }
};