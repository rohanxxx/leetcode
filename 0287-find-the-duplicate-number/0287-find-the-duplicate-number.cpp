class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for(int i = 0; i < nums.size(); i++){
            int cur = abs(nums[i]);
            if(nums[cur] < 0){
                duplicate = cur;
            }
            nums[cur] *= -1;
        }
        for(auto num: nums) num = abs(num);
        return duplicate;
    }
};