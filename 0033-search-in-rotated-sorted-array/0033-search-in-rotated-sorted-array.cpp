class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            //check left portion first
            if(nums[left] <= nums[mid]){
                if(target > nums[mid] || target < nums[left]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            else{//checks the right portion
                if(target < nums[mid] || target > nums[right]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};