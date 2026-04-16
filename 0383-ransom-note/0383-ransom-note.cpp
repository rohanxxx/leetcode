class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26,0);
        for(char c: ransomNote){
            map[c-'a']++;
        }
        for(char c: magazine){
            if(map[c-'a'] > 0){
                map[c-'a']--;
            }
        }
        for(int i = 0; i < 26; i++){
            if(map[i] > 0){
                return false;
            }
        }
        return true;
    }
};