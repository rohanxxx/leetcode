/*
    n = 5
    my turn -> 1
    friends turn -> 

    n = 6
    x -> 2
    y -> 1 || 2 || 3 regardless of his choices the outcome is still in my favor
*/
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};