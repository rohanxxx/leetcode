/*
    A reverse pair is a pair (i, j) where:
        0 <= i < j < nums.length and
        nums[i] > 2 * nums[j].

            0 1 2 3 4
    nums = [1,3,2,3,1]

    1 -> 1
    2 -> 1
    3 -> 2


            
*/
class Solution {
public:
    void merge(int lo, int mid, int hi, vector<int>& nums){
        int left = lo, right = mid+1;
        
        vector<int> temp;
        while(left <= mid && right <= hi){
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid){
            temp.push_back(nums[left++]);
        }

        while(right <= hi){
            temp.push_back(nums[right++]);
        }

        for(int i = lo; i <= hi; i++){
            nums[i] = temp[i-lo];
        }
    }
    int mergeSortandCount(int lo, int hi, vector<int>& nums){
        if(lo >= hi) return 0;

        int count = 0;
        int mid = lo + (hi-lo)/2;
        count += mergeSortandCount(lo, mid, nums);
        count += mergeSortandCount(mid+1, hi, nums);

        int left = lo, right = mid+1;
        while(left <= mid){
            while(right <= hi && nums[left] > (long long)2*nums[right]){
                right++;
            }
            count += (right-(mid+1));
            left++;
        }
        merge(lo, mid, hi, nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSortandCount(0, n-1, nums);
    }
};