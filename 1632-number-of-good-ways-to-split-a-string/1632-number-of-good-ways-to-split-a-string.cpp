class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> leftMap, rightMap;
        for(char c: s){
            rightMap[c]++;
        }

        int goodSplitCount = 0;
        for(char c: s){
            leftMap[c]++;
            rightMap[c]--;
            if(rightMap[c] == 0){
                rightMap.erase(c);
            }
            if(leftMap.size() == rightMap.size()){
                goodSplitCount++;
            }
        }

        return goodSplitCount;
    }
};