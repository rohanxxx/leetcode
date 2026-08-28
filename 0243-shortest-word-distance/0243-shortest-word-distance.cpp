/*
                            0.       1.       2.        3.        4
    Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
    Output: 3
                        0.            1.      2.         3.       4. 
    Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
    Output: 1

    makes = 1, 4,
    coding = 3
*/
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {

        pair<string, int> prev = {"", -1};

        int n = wordsDict.size();

        int minDist = INT_MAX;
        for(int i = 0; i < n; i++){
            if(!(word1 == wordsDict[i] || word2 == wordsDict[i])){
                continue;
            }
            if(prev.first != "" && prev.first != wordsDict[i]){
                minDist = min(minDist, i-prev.second);
            }
            prev.first = wordsDict[i];
            prev.second = i;
        }

        return minDist;
    }
};