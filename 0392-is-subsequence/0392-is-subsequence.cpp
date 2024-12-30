class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int len = s.length();
        for(char c: t){
            if(i < len && c == s[i]) i++;
        }

        if (i < len) return false;
        return true;
    }
};