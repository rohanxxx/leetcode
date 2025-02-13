class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool aliceTurn = true;
        bool bobTurn = false;
        while(n >= 0){
            if(aliceTurn){
                if(n-remove < 0){
                    return false;
                }
                n -= remove;
                remove--;
                bobTurn = true;
                aliceTurn = false;
                continue;
            }
            if(bobTurn){
                if(n-remove < 0){
                    return true;
                }
                n -= remove;
                remove--;
                bobTurn = false;
                aliceTurn = true;
            }
        }

        return true;
    }
};