class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& num: nums) mp[num]++;
        vector<pair<int, int>> v;
        for(auto it = mp.begin(); it != mp.end(); it++){
            // ans.push_back({it->first, it->second});
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end());

        vector<int> ans;
        for(int i = v.size()-1; i >= 0; i--){
            if(k) ans.push_back(v[i].second);
            else break;
            k--;
        }
        return ans;
    }
};