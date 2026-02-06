/*
                    0   1  2  3 4
    Input: nums = [-1,--3,-4,-2,2]
    Output: 2
                    0 1  2 3 4
    Input: nums = [-3,1,-3,4,2]
    Output: 3
    
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                duplicate = abs(nums[i]);
                break;
            }
            nums[index] = nums[index]*(-1);
        }
        for(int i = 0; i < n; i++){
            nums[i] = abs(nums[i]);
        }
        return duplicate;
    }
};