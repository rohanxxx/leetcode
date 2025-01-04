class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) return s.length();

        string temp = "0"+s;
        s = temp;

        int start = 1;
        int maxLen = 0;

        unordered_map<char, int> seen;
        for(int i = 0; i < s.length(); i++){
            if(seen[s[i]]){
                // cout << "i: " << i << endl;
                if(start <= seen[s[i]]) {
                    start = seen[s[i]]+1;
                }
            }
            maxLen = max(maxLen, i-start);
            seen[s[i]] = i;
        }

        return maxLen+1;
    }
};