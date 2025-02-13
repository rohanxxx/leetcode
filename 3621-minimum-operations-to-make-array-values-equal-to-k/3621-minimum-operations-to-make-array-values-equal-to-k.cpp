class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minElement = *min_element(nums.begin(), nums.end());
        if(minElement < k){
            return -1;
        }

        unordered_map<int, int> mp;
        for(int n: nums){
            mp[n] = 1;
        }

        int ans = mp.size();
        if(mp[k]) ans--;

        return ans;
    }
};