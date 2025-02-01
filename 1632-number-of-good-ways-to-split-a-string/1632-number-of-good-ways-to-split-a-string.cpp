class Solution {
public:
    int numSplits(string s) {
        int count = 0;
        unordered_map<char, int> leftMap, rightMap;
        for(char c: s) leftMap[c]++;
        for(int i = s.length()-1; i >= 0; i--){
            leftMap[s[i]]--;
            rightMap[s[i]]++;
            
            if(leftMap[s[i]] == 0) leftMap.erase(s[i]);
            if((int)leftMap.size() == (int)rightMap.size()) count++;
        }

        return count;
    }
};