/*
    nums = {1,2,2,2,3,4,5}
    nums = {}
    
    nums = {1,2,3,4,5,6,7} op->1 + 2 + 2 + 2 + 2

*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operationCount = 0;
        
        //TC: O(N) N->nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) {
                continue;
            }
            
            //prev = 1; nums[i] = prev+1;
            int dif = nums[i-1] - nums[i];
            nums[i] = nums[i]+dif+1;
            operationCount += (dif+1);
        }
        return operationCount;
    }
};