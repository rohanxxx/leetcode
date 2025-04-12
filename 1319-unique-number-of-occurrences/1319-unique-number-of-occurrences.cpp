class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int num: arr) freq[num]++;

        unordered_map<int, int> mp;
        for(auto f: freq){
            if(mp[f.second]) return false;
            mp[f.second]++;
        }
        return true;
    }
};