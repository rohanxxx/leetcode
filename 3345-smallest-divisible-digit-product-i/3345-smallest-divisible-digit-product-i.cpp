class Solution {
public:
    long long get_product(int& n){
        int x = n;
        long long product = 1;
        while(x > 0){
            int digit = x % 10;
            product *= digit;
            x = x/10;
        }

        return product;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 100; i++){
            long long product = get_product(i);
            if(product % t == 0){
                return i;
            }
        }

        return -1;
    }
};