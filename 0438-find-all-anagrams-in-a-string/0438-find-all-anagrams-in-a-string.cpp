class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        
        vector<int> ans;
        vector<int> smap(26, 0), pmap(26, 0);

        int len = p.size();
        for(char& i: p) pmap[i-'a']++;
        for(int i = 0; i < len-1; i++) smap[s[i]-'a']++;
        
        
        for(int i = len-1; i < s.length(); i++){
            int index = i-(len-1);
            // cout << "i: " << i << endl;
            // cout << "len: " << len << endl;
            // cout << "i-len-1: " << i-(len-1) << endl;
            // cout << "index: " << index << endl;
            smap[s[i]-'a']++;
            if(smap == pmap) ans.push_back(index);
            
            smap[s[index]-'a']--;

        }
        return ans;
    }
};