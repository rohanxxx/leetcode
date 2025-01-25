class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        vector<int> s1map(26, 0), s2map(26, 0);
        for(int i = 0; i < s1.length(); i++) {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }
        if(s1map == s2map) return true;
        for(int i = s1.length(); i < s2.length(); i++){
            int index = i - s1.length();
            
            s2map[s2[i]-'a']++;
            s2map[s2[index]-'a']--;
            if(s2map == s1map) return true;
        }

        return false;
    }
};