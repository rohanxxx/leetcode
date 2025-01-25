class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        vector<int> ans;
        vector<int> smap(26, 0), pmap(26, 0);

        int pLen = p.length();

        for(char& c: p) pmap[c-'a']++;
        for(int i = 0; i < pLen-1; i++) smap[s[i]-'a']++;

        for(int i = pLen-1; i < s.length(); i++){
            int index = i - (pLen-1);
            smap[s[i]-'a']++;
            
            if(smap == pmap) ans.push_back(index);

            smap[s[index]-'a']--;
        }

        return ans;
    }
};