class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;
        vector<int> ransomMap(26, 0), magazineMap(26, 0);
        for(char c: ransomNote) ransomMap[c-'a']++;
        for(char c: magazine) magazineMap[c-'a']++;

        for(char c: ransomNote){
            if(ransomMap[c-'a'] > magazineMap[c-'a']) return false;
        }
        return true;
    }
};