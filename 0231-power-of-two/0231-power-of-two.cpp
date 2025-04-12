class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i <= n; i++){
            if((long long)pow(2, i) == n){
                return true;
            }
            if((long long)pow(2, i) > n){
                return false;
            }
        }
        return false;
    }
};