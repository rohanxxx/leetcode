class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string& word1, const string& word2){return word1.length() < word2.length();});
        int longestSequenceCount = 0;
        for(const string& word: words){
            int curLen = 1;
            for(int i = 0; i < word.length(); i++){
                string predecessor = word.substr(0,i)+word.substr(i+1, word.length()+1);
                if(dp.find(predecessor) != dp.end()){
                    curLen = max(curLen, dp[predecessor]+1);
                }
            }

            dp[word] = curLen;
            longestSequenceCount = max(longestSequenceCount, curLen);
        }

        return longestSequenceCount;
    }
};