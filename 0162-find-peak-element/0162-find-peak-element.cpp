/*
    1 0 1

    [1,2,3,1]

     0 1 2 3 4 5 6
    [1,2,1,3,5,6,4]
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[mid+1]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }

        return left;
    }
};