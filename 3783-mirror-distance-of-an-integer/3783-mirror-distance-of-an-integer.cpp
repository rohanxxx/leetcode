/*
    25 -> 52
    |25-52| => 27
    10 -> 1

*/
class Solution {
public:
    int reverseNum(int n){
        int num = 0;
        while(n){
            int digit = n % 10;
            n = n / 10;
            num = num * 10 + digit;
        }
        return num;
    }
    int mirrorDistance(int n) {
        return (int)abs(n-reverseNum(n));
    }
};