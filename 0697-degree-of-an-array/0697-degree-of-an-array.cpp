class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxDegree = 0;
        unordered_map<int, int> freq, mp;
        for(int num: nums){
            // freq[num]++;
            maxDegree = max(maxDegree, ++freq[num]);
        }
        int left = 0, minLen = INT_MAX;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++;
            while(mp[nums[right]] == maxDegree){
                minLen = min(minLen, right-left+1);
                mp[nums[left]]--;
                left++;
            }
        }
        return minLen;
    }
};