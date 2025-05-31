/*
                   0 1 2 3 4 5
    Input: nums = [0,2,1,5,3,4]
                   0 1 2 3 4 5
                   0 1
    Output: [0,1,2,4,5,3]
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};