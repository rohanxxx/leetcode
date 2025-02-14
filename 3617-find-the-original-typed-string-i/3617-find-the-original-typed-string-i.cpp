class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1, totalCount = 1;
        for(int i = 1; i < word.length(); i++){
            if(word[i] != word[i-1]){
                totalCount += (count-1);
                count = 1;
                continue;
            }
            count++;
        }
        totalCount += (count-1);
        return totalCount;
    }
};