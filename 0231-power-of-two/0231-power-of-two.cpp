class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long pow = 2;

        if(n == 1 || n == 2) return true; 
        for(int i = 2; i <= n; i++){
            pow *= 2;
            if(pow == n) return true;
            if(pow > n) return false;
        }

        return false;
    }
};