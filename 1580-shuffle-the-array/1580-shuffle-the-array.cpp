/*
    Input: nums = [2,5,1,3,4,7], n = 3
    Output: [2,3,5,4,1,7] 

     0 1 2 3 4 5
    [2,5,1,3,4,7] size = 6

    for(i = 0; i < n; i++){
        ans.push_back(nums[i]);
        ans.push_back(nums[i+n]);
    }
    return ans;
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};