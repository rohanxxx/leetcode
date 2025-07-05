/*
    [0,1,1,1,0,0]
     1 0 0 1 0 0
     1 1 1 0 0 0
     1 1 1 1 1 1
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), count = 0;
        //TC: O(N)
        for(int i = 0;  i < n-2; i++){
            if(nums[i] == 0){
                nums[i] = (!nums[i]);
                nums[i+1] = (!nums[i+1]);
                nums[i+2] = (!nums[i+2]);
                count++;
            }
        }
        //TC: O(N)
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return -1;
        }
        return count;
    }
};