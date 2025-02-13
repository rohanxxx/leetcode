class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 2; i < nums.size(); i++){
            if(((nums[i] + nums[i-2])*2) == nums[i-1]){
                count++;
            }
        }
        return count;
    }
};