/*
    8 4 2 1
    0 1 0 1 -> 5
    0 0 1 0 -> 2
    0 0 0 1 -> 1

    8 4 2 1 
    0 1 1 1 -> 7
    0 0 1 1 -> 3
    0 0 0 1 -> 1

    0 1 0 0 -> 4

    8 4 2 1
    0 1 0 1 -> 5
    0 1 1 0 -> 6
    0 1 1 1 -> 7
    1 0 0 0 -> 8
    1 0 0 1 -> 9
    1 0 1 0 -> 10
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // find the common 1-bits
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};