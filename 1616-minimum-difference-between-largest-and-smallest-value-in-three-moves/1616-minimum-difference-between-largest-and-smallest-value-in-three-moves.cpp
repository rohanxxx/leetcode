class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        int minDif = INT_MAX;

        for(int left = 0, right = nums.size()-4; left < 4; left++, right++){
            minDif = min(minDif, nums[right]-nums[left]);
        }
        return minDif;
    }
};