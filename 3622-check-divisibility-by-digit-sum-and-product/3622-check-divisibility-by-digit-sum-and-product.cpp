class Solution {
public:
    bool checkDivisibility(int n) {
        int val = n;
        long long sum = 0;
        long long product = 1;
        while(n){
            int digit = n % 10;

            sum += digit;
            product *= digit;

            n /= 10;
        }

        return (val % (sum + product) == 0);
    }
};