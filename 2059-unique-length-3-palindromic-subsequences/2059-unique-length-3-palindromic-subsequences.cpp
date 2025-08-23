class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        //SC: O(26)
        unordered_set<char> letters;
        //TC: O(N)
        for(char& c: s) letters.insert(c);
        //TC: O(26*(N+N))
        for(auto& letter: letters){
            int i = -1, j = 0;
            //TC: O(N)
            for(int k = 0; k < s.length(); k++){
                if(s[k] == letter){
                    if(i == -1) i = k;
                    j = k;
                }
            }

            unordered_set<char> inBetween;
            //TC: O(N)
            for(int k = i + 1; k < j; k++) inBetween.insert(s[k]);

            ans += inBetween.size();
        }

        return ans;
    }
};