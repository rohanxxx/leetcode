class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t revBit = 0, power = 31;
        while(n!=0){
            revBit += (n&1) << power;
            n = n >> 1;
            power -= 1;
        }
        return revBit;
    }
};