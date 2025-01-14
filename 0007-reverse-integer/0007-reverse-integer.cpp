class Solution {
public:
    int reverse(int x) {
        int reverseInteger = 0;
        while(x){
            int pop = x%10;
            
            if(reverseInteger > INT_MAX/10 || (reverseInteger == INT_MAX && pop > 7)) return 0;
            if(reverseInteger < INT_MIN/10 || (reverseInteger == INT_MIN && pop < -8)) return 0;
            
            reverseInteger = reverseInteger*10 + pop;
            
            x /= 10;
        }
        return reverseInteger;
    }
};