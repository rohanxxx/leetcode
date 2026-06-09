/*
                   0 1 2 3
    Input: nums = [4,2,5,1], k = 3
    Output: 12

    maxSoFar = 4 4 5 5 => 5 5 4 4

    [4,2,5,1]

    0 - 3 => 5-1 =>4
    1 - 3 => 5-1 =>4
    2 - 3 => 5-1 =>4

    [1,3,2]
    0 - 2 => 3-1 => 2
    1 - 2 => 3-2 => 1


    maxSoFarFromLeft = 3 3 1
    minSoFarFromRight= 1 1 1
*/
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        return (long long)(maxi-mini)*k;
    }
};