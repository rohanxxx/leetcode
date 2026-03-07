/*
      0 1 2 3 4 5   6  7
    [10,9,2,5,3,7,101,18]

    10x, 9x, 2, 3, 7, 18,    
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxSize = 0;
        vector<int> ans; 
        ans.push_back(nums[0]);
        maxSize = max(maxSize, (int)ans.size());
        for(int i = 1; i < n; i++){
            if(ans.back() >= nums[i]){
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
            else{
                ans.push_back(nums[i]);
            }

            maxSize = max(maxSize, (int)ans.size());
        }

        return maxSize;
    }
};