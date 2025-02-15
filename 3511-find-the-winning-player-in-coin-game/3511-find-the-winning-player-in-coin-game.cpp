class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = 0;
        while(x > 0 && y > 3){
            x--;
            y -= 4;
            moves++;
        }
        if(moves%2){
            return "Alice";
        }
        return "Bob";
    }
};