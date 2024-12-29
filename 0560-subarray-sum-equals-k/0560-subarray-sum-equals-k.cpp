class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; mp[0] = 1;
        int prefixSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int difference = (prefixSum-k);
            // cout << "difference: " << difference << endl;
            if(mp.find(difference) != mp.end()){
                count += mp[difference];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};