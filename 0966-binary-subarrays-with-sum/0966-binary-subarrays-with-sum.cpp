class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currSum = 0;
        unordered_map<int, int> frequency;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(currSum == goal) totalCount++;
            if(frequency.find(currSum-goal) != frequency.end()){
                totalCount += frequency[currSum-goal];
            }
            frequency[currSum]++;
        }
        return totalCount;
    }
};