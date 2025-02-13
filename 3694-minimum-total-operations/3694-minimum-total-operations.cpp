class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), minOpsCount = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                minOpsCount++;
            }
        }
        return minOpsCount;
    }
};