class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto& num: arr){
            mp[num]++;
        }

        vector<int> v;
        for(auto it= mp.begin(); it != mp.end(); it++){
            v.push_back(it->second);
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[i-1]) return false;
        }
        return true;
    }
};