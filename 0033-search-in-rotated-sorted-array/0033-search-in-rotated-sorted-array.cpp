/*
               0 1 2 3 4 5 6
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

while(l < r){
    int mid = left + (right-left)/2;
    if(nums[mid] == target) return mid;
    
    //left sorted porion
    if(nums[l] <= nums[mid]){
        if(target > nums[mid] || target < nums[l]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    else{ //right sorted array
        if(target < nums[mid] || target > nums[r]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    return -1;
}
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;

        while(l <= r){
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        
        //left sorted porion
        if(nums[l] <= nums[mid]){
            if(target > nums[mid] || target < nums[l]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        else{ //right sorted array
            if(target < nums[mid] || target > nums[r]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        }

        return -1;
        }
};