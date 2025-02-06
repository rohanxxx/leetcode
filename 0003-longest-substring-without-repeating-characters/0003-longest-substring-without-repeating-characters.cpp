class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] >= start){
                    maxLen = max(maxLen, i-start);
                    if(mp[s[i]] > start) start = (mp[s[i]] + 1);
                    else start++;
                }
            }
            mp[s[i]] = i;
        }
        maxLen = max(maxLen, (int)s.length()-start);
        return maxLen;
    }
};