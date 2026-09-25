/*
    number of pairs (i,j) where 0 <= i < j < n and nums[i] + nums[j] < target

    Input: nums = [-1,1,2,3,1], target = 2
    Output: 3

     0 1 2 3 4
    -1 1 1 2 3 target = 2

    0,1 -> 0,2 -> 0,3
*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i]+nums[j] < target){
                    count++;
                }
            }
        }

        return count;
    }
};