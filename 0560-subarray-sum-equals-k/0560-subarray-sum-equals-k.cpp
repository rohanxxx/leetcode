class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix = 0, count = 0;
        for(auto& n: nums){
            prefix += n;
            int d = prefix - k;

            if(mp[d]) count+= mp[d];
            mp[prefix]++;
        }

        return count;
    }
};