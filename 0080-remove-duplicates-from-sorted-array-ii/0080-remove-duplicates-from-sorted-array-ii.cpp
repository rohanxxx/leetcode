class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int k = 1, count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[k++] = nums[i];
                count = 0;
                continue;
            }
            else count++;
            if(count == 1){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};