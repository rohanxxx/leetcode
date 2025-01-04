class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        vector<int> ans;
        vector<int> s1map(26, 0), s2map(26, 0);

        int len = s1.length();
        for(int i = 0; i < len; i++){
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }

        if(s1map == s2map) return true;

        for(int i = len; i < s2.length(); i++){
            int index = i-len;
            s2map[s2[i]-'a']++;
            s2map[s2[index]-'a']--;
            if(s2map == s1map) return true;
        }

        return false;
    }
};