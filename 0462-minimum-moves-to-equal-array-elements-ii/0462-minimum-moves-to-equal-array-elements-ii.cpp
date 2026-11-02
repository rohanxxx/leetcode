/*
                   0  1 2 3
    Input: nums = [1,10,2,9]
    Output: 16
*/
class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int k){
        int pivotVal = nums[right];
        int i = left;

        for(int j = i; j <= right; j++){
            if(nums[j] < pivotVal){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[right], nums[i]);
        return i;
    }
    int select(vector<int>& nums, int left, int right, int k){
        if(left == right){
            return nums[left];
        }
        int pivotIndex = partition(nums, left, right, k);
        if(k == pivotIndex){
            return nums[k];
        }
        else if(k < pivotIndex){
            return select(nums, left, pivotIndex-1, k);
        }
        else{
            return select(nums, pivotIndex+1, right, k);
        }
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = select(nums, 0, n-1, n/2);
        
        int count = 0;
        for(auto num: nums){
            count += (abs(num-median));
        }
        return count;
    }
};