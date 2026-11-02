/*
                   0  1 2 3
    Input: nums = [1,10,2,9]
    Output: 16
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int mid = nums[nums.size()/2];
        for(auto num: nums){
            count += (abs(num-mid));
        }
        
        return count;
    }
};