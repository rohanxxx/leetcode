class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> mp;
        
        for(auto& n: nums){
            mp[n]++;
        }

        vector<pair<int, int>> v;
        for(auto it = mp.begin(); it != mp.end(); it++){
            v.push_back({it->second, it->first});
        }

        sort(v.begin(), v.end());

        for(int i = v.size()-1; i >= 0 && k > 0; i--, k--){
            result.push_back(v[i].second);
        }

        return result;
    }
};