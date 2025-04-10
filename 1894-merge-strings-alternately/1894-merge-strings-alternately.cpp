class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int minSize = min(word1.size(), word2.size());
        for(int i = 0; i < minSize; i++){
            ans += word1[i];
            ans += word2[i];
        }

        if(word1.size() > minSize){
            ans += word1.substr(minSize);
        }
        if(word2.size() > minSize){
            ans += word2.substr(minSize);
        }

        return ans;
    }
};