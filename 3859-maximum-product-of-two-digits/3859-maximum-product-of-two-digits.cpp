class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n){
            int pop = n % 10;
            digits.push_back(pop);
            n = n / 10;
        }
        sort(digits.begin(), digits.end());
        int size = digits.size();
        if(size < 2) return 0;
        long long ans = (long long)digits[size-1] * digits[size-2];
        return ans;
    }
};