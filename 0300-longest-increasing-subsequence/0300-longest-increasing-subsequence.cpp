class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> subArr;
        subArr.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if(num > subArr.back()){
                subArr.push_back(num);
            }
            else{
                int index = lower_bound(subArr.begin(), subArr.end(), num) - subArr.begin();
                subArr[index] = nums[i];
            }
        }
        return subArr.size();
    }
};