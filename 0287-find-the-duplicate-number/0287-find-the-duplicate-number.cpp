class Solution {
    /*
    [ 0, 1, 2, 3, 4]
    [ 1,-3,-4,-2,-2]
    */
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]);
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