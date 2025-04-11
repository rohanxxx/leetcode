class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(char c: s) mp1[c]++;
        for(char c: t) mp2[c]++;
        for(char c: s){
            if(mp2[c] == 0 || mp1[c] != mp2[c]) return false;
        }
        for(char c: t){
            if(mp1[c] == 0 || mp1[c] != mp2[c]) return false;
        }
        return true;
    }
};