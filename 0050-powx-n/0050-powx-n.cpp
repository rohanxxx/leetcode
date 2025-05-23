class Solution {
public:
    double binaryExp(double x, long long n){
        if(n == 0) return 1.0;
        if(n < 0) return 1.0/binaryExp(x, -1*n);
        
        if(n%2) return x * binaryExp(x*x, n/2);
        else return binaryExp(x*x, n/2);
    }
    double myPow(double x, int n) {
        return binaryExp(x, static_cast<long long>(n)); 
    }
};