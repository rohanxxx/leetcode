class Solution {
public:
    /*
        nums arr 
        delete one element from it

        return the size of the longest non-empty subarray containing only 1's

        return 0 if there is no such subarray
    */
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0), rightSum(n, 0);

        int left = 0, right = 0;
        
        leftSum[0] = nums[0];
        rightSum[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            if(nums[i] == 1){
                leftSum[i] = leftSum[i-1]+nums[i];
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == 1){
                rightSum[i] = rightSum[i+1]+nums[i];
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i-1 >= 0 && i+1 < n){
                count = max(count, leftSum[i-1]+rightSum[i+1]);
            }
            else{
                count = max(count, leftSum[i]);
            }
        }

        if(count == n) return count-1;
        return count;
    }
};