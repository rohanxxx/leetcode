class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        while(n){
            int pop = n % 10;
            prod = prod * pop;
            sum = sum + pop;

            n = n / 10;
        }

        return prod - sum;
    }
};