class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDif = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            maxDif = max(maxDif, abs(nums[i]-nums[i-1]));
        }
        maxDif = max(maxDif, abs(nums.back()-nums[0]));
        return maxDif;
    }
};