class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, sSize = s.length();
        for(char c: t){
            if(s[i] == c) i++;
            if(i == sSize) return true;
        }
        if(i == sSize) return true;
        return false;
    }
};