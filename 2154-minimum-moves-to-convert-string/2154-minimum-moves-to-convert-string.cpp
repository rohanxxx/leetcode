class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), ops = 0;
        while(i < n){
            if(s[i] == 'O') i++;
            else ops++, i+= 3;
        }
        return ops;
    }
};