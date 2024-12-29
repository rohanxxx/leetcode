class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> seen(nums.size()+1, 0);
        for(auto num: nums){
            if(num > 0 && num <= nums.size()){
                seen[num]++;
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            if(!seen[i]) return i;
        }
        return nums.size()+1;
    }
};