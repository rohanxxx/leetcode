class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) return s.length();
        
        string temp = "0"+s;
        s = temp;
        
        int start = 1;
        int maxLen = 0;
        unordered_map<char, int> last_seen;
        for(int i = 1; i < s.length(); i++){
            if(last_seen[s[i]]){
                if(start <= last_seen[s[i]]){
                    start = last_seen[s[i]]+1;
                }
            }
            maxLen = max(maxLen, i-start);
            last_seen[s[i]] = i;
        }
        return maxLen+1;
    }
};