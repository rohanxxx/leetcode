class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), minOpsCount = 0;
        for(int i = 1, prev = nums[0]; i < n; i++){
            if(nums[i] != prev){
                prev = nums[i];
                minOpsCount++;
            }
        }
        return minOpsCount;
    }
};