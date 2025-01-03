class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefix = 0;
        unordered_map<int, int> mp; mp[0] = 1;
        for(int& num: nums){
            prefix += num;
            int dif = prefix-k;
            
            if(mp[dif]) count += mp[dif];
            mp[prefix]++;
        }
        return count;
    }
};