class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> smap(26, 0), tmap(26, 0);
        for(char c: s) smap[c-'a']++;
        for(char c: t) tmap[c-'a']++;

        /*for(int i = 0; i < 26; i++){
            if(smap[i] != tmap[i]) return false;
        }*/
        if(smap != tmap) return false;

        return true;
    }
};