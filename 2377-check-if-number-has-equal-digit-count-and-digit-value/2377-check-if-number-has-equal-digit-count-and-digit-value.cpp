class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> mp;
        for(auto& digit: num) mp[digit-'0']++;
        for(int i = 0; i < num.length(); i++){
            if(mp[i] != num[i]-'0') return false;
        }
        return true;
    }
};