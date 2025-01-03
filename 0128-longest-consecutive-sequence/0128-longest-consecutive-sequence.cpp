class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 1;
        int maxCount = 1;
        
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-prev == 1){
                count++;
                maxCount = max(maxCount, count);
            }
            else{
                if(nums[i]-prev > 1) count = 1;
            }

            prev = nums[i];
        }

        return maxCount;
    }
};