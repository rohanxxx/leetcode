/*
    "a"
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        //SC: O(56)
        vector<int> lowerMap(26, 0), upperMap(26,0);
        //TC: O(N)
        for(auto c: word){
            if(c-'a' >= 0 && c-'a' < 26){
                lowerMap[c-'a']++;
            }
            if(c-'A' >= 0 && c-'A' < 26){
                upperMap[c-'A']++;
            }
        }

        int count = 0;
        //O(26)
        for(int i = 0; i < 26; i++){
            if(lowerMap[i] > 0 && upperMap[i] > 0){
                count++;
                lowerMap[i]--;
                upperMap[i]--;
            }
        }

        return count;
    }
};