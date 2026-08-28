class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        pair<string, int> prev = {"", -1};

        int n = wordsDict.size();

        int minDist = INT_MAX;
        for(int i = 0; i < n; i++){
            if(!(word1 == wordsDict[i] || word2 == wordsDict[i])){
                continue;
            }
            if(prev.first != "" && ((word1 != word2 && prev.first != wordsDict[i]) || (word1 == word2 && prev.first == wordsDict[i]))){
                minDist = min(minDist, i-prev.second);
            }
            prev.first = wordsDict[i];
            prev.second = i;
        }

        return minDist;
    }
};