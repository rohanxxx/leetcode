class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n <= 100){
            int temp = n;
            int digitProduct = INT_MIN;
            while(temp){
                int pop = temp % 10;
                if(digitProduct == INT_MIN){
                    digitProduct = 1;
                }
                digitProduct *= pop;
                temp = temp / 10;
            }
            if(digitProduct != INT_MIN){
                if(digitProduct % t == 0){
                    return n;
                }
            }
            n++;
        }
        return -1;
    }
};