class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int sum1 = (1+(c1[0]-'a'))+(c1[1]-'0');
        int sum2 = (1+(c2[0]-'a'))+(c2[1]-'0');
        
        if(sum1%2 == 0 && sum2%2 == 0) return true;
        if(sum1%2 == 1 && sum2%2 == 1) return true;
        return false;
    }
};