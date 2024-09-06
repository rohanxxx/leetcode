class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;

        int maxUniq = INT_MIN;
        for(auto& it: mp){
            if(it.second == 1){
                maxUniq = max(maxUniq, it.first);
            }
        }

        if(maxUniq == INT_MIN) return -1;
        
        return maxUniq;
    }
};