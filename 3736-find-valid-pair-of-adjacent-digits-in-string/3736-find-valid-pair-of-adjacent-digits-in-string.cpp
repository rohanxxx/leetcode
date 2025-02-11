class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int, int> mp;
        for(char c: s){
            mp[c-'0']++;
        }
        for(int i = 1; i < s.length(); i++){
            if(s[i] != s[i-1]){
                if(((s[i]-'0') == mp[s[i]-'0']) && ((s[i-1]-'0') == mp[s[i-1]-'0'])){
                    return (string) ""+s[i-1]+s[i];
                }
            }
        }
        return "";
    }
};