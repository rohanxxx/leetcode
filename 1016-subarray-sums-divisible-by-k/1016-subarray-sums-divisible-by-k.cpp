class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;
        for(auto& num: nums){
            sum += num;
            int remainder = sum % k;
            if(remainder < 0) remainder += k;
            if(mp[remainder]) count += mp[remainder];
            mp[remainder]++;
        }
        return count;
    }
};