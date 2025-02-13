class Solution {
public:
    int smallestNumber(int n) {
        int totalBits = log2(n)+1;
        return (int)(1<<totalBits)-1;
    }
};