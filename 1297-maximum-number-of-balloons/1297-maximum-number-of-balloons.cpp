class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount = 0;
        int aCount = 0;
        int lCount = 0;
        int oCount = 0;
        int nCount = 0;

        for(char c: text){
            if(c == 'b') bCount++;
            if(c == 'a') aCount++;
            if(c == 'l') lCount++;
            if(c == 'o') oCount++;
            if(c == 'n') nCount++;
        }
        lCount = lCount/2;
        oCount = oCount/2;
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};