/*
    Input: nums = [1,2,3]
    Output: 3
    Explanation: Only three moves are needed (remember each move increments two elements):
    [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            count += nums[i] - nums[0];
        }

        return count;
    }
};