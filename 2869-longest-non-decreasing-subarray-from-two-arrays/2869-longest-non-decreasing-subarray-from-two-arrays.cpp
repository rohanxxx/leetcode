class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        int maxSubArr = 0;
        vector<vector<int>> dp(size, vector<int>(2, 0));
        
        for (int i = 1; i < size; ++i) {
            int imin = min(nums1[i], nums2[i]);
            int imax = max(nums1[i], nums2[i]);
            int jmin = min(nums1[i - 1], nums2[i - 1]);
            int jmax = max(nums1[i - 1], nums2[i - 1]);
            
            if (imin >= jmin) dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0]);
            if (imin >= jmax) dp[i][0] = max(dp[i - 1][1] + 1, dp[i][0]);
            if (imax >= jmin) dp[i][1] = max(dp[i - 1][0] + 1, dp[i][1]);
            if (imax >= jmax) dp[i][1] = max(dp[i - 1][1] + 1, dp[i][1]);
            
            maxSubArr = max(maxSubArr, dp[i][0]);
            maxSubArr = max(maxSubArr, dp[i][1]);
        }
        
        return maxSubArr + 1;
    }
};