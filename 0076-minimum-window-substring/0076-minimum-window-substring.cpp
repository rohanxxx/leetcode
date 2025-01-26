class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto& c: t) mp[c]++;

        int minLen = INT_MAX, count = t.length();
        int left = 0, right = 0, startIndex = 0;

        int sSize = s.length();
        while(right < sSize){
            if(mp[s[right]] > 0) count--;
            
            mp[s[right++]]--;
            while(count == 0){
                if(right-left < minLen){
                    startIndex = left;
                    minLen = right-left;
                }
                mp[s[left]]++;
                if(mp[s[left++]] > 0) count++;
            }
        }
        if(minLen != INT_MAX) return s.substr(startIndex, minLen);
        return "";
    }
};