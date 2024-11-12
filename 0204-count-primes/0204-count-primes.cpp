class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> numbers(n, true);
        for(int p = 2; p <= sqrt(n); p++){
            if(numbers[p]){
                for(int i = p*p; i < n; i+=p){
                    numbers[i] = false;
                }
            }
        }

        int numberOfPrimes = 0;
        for(int i = 2; i < n; i++){
            if(numbers[i]) numberOfPrimes++;
        }

        return numberOfPrimes;
    }
};