/*
                    0 1 2 3
    Input: nums = [10,4,8,3]

    leftSum  = 0, 10, 14, 22
    rightSum = 15, 11, 3, 0
    Output: [15,1,11,22]


*/
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++){
            sum += nums[i-1];
            ans[i] = sum;
        }

        sum = 0;
        for(int i = n-2; i >= 0; i--){
            sum += nums[i+1];
            ans[i] = abs(ans[i]-sum);
        }

        return ans;
    }
};