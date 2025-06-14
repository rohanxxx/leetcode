/*

                   0 1 2 3 4
    Input: nums = [2,2,2,0,1]
    Output: 0

    lo = 0, hi = 4, (4+1)/2 = 2
    lo = 2+1 = 3, hi = 4, (3+4)/2 = 3
    lo 3, hi = 3

    
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi){
            int pivot = lo + (hi-lo)/2;
            if(nums[pivot] < nums[hi]) hi = pivot;
            else if (nums[pivot] > nums[hi]) lo = pivot + 1;
            else hi--;  
        }
        return nums[lo];
    }
};