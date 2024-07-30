class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0, diff = INT_MIN, subArrCount = 0;

        mp[prefixSum] = 1;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            diff = prefixSum - k;
            if(mp.find(diff) != mp.end()){
                subArrCount += mp[diff];
            }
            mp[prefixSum]++;
        }

        return subArrCount;
    }
};