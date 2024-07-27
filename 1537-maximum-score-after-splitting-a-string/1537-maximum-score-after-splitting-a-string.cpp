class Solution {
public:
    int maxScore(string s) {

        // if(s.length() == 2){

        // }
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
            // cout << "count: " << count << endl;
            maxScore = max(countAllOnes-countOne+countZero, maxScore);
            cout << "maxScore: " << maxScore << endl;
        }

        return maxScore;
    }
};