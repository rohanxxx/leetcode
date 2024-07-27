class Solution {
public:
    int maxScore(string s) {

        int countAllOnes = 0;
        for(auto& c: s){
            if(c == '1') countAllOnes++;
        }

        int countOne = 0;
        int countZero = 0;
        int maxScore = INT_MIN;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == '1') countOne++;
            else countZero++;
            maxScore = max(countAllOnes-countOne+countZero, maxScore);
        }

        return maxScore;
    }
};