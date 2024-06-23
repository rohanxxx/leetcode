class Solution {
public:
    int reverse(int x) {
        int rev_int = 0;
        while(x){
            int pop = x%10;
            if(rev_int > INT_MAX/10 || (rev_int == INT_MAX/10 && pop > 7)) return 0;
            if(rev_int < INT_MIN/10 || (rev_int == INT_MIN/10 && pop < -8)) return 0;
            rev_int = rev_int * 10 + pop;
            x /= 10;
        }
        return rev_int;
    }
};