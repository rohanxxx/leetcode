class Solution {
public:
    string sortString(string s) {
        unordered_map<int, int> frequency;
        for(char& c: s) frequency[c-'a']++;
        string res = "";
        // int count = 
        while(res.length() != s.length()){
            for(int i = 0; i < 26; i++){
                if(frequency[i] != 0){
                    res += char(i+'a');
                    frequency[i]--;
                    if(res.length() == s.length()) return res;
                }
            }
            if(res.length() == s.length()) return res;
            for(int i = 25; i >= 0; i--){
                if(frequency[i] != 0){
                    res += char(i+'a');
                    frequency[i]--;
                    if(res.length() == s.length()) return res;
                }
            }
        }
        return res;
    }
};