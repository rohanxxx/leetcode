/*
     0 1 2 3 4 5 6 7 8
    [1,1,2,3,3,4,4,8,8]
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0){
            return -1;
        }

        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            // check if mid is the single element
            if((mid == 0 || nums[mid] != nums[mid-1]) &&
               (mid == n-1 || nums[mid] != nums[mid+1])){
                return nums[mid];
            }
            // case 1: pair with right
            else if(mid+1 < n && nums[mid] == nums[mid+1]){
                int len = right - mid + 1;
                if(len % 2 == 1) left = mid + 2;
                else right = mid - 1;
            }

            // case 2: pair with left
            else if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
                int len = mid - left + 1;
                if(len % 2 == 1) right = mid - 2;
                else left = mid + 1;
            }
        }

        return -1;
    }
};