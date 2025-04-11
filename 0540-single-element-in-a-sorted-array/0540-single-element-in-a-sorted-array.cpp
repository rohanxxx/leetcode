class Solution {
public:
    int binarySearch(int left, int right, int& n, vector<int>& nums){
        if(left > right) return -1;
        int mid = (right+left)/2;
        bool lc = false;
        bool rc = false;
        if(mid-1 >= 0){ 
            if(nums[mid-1] != nums[mid]) lc = true;
        }
        else lc = true;
        if(mid+1 < n) {
            if(nums[mid] != nums[mid+1]) rc = true;
        }
        else rc = true;
        if(lc == true && rc == true) {
            // cout << "mid: " << mid << endl;
            return mid;
        }
        int checkLeft = binarySearch(left, mid-1, n, nums);
        if(checkLeft > -1) return checkLeft;
        int checkRight = binarySearch(mid+1, right, n, nums);
        return max(checkLeft, checkRight);
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int index = binarySearch(0, n-1, n, nums);
        if(index != -1) return nums[index];
        return -1;
    }
};