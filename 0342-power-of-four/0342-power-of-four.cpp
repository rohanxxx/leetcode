/*
    8%4 = 0 8/4 = 2
    2%4 = 2 x

    2 != 1 return false

    16 % 4 = 0 16/4 = 4
    4 % 4  = 0 4/4 = 1
    1 == 1 return true

    64%4 = 0 64/4 = 16
    16%4 = 0 16/4 = 4
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        while(n % 4 == 0) n = n / 4;
        return n == 1;
    }
};