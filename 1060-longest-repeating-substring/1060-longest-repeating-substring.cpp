/*
"aabcaabdaab"
aa
aab
aabc

*/
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int len = 0;
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                map[temp]++;
                if(map[temp] > 1){
                    len = max(len, (int)temp.size());
                }
            }
        }
        return len;
    }
};