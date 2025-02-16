class Solution {
public:
    int fib(int n) {
        if(n == 1) return 1;
        int f1 = 0, f2 = 1, f3 = 0;
        for(int i = 0; i < n-1; i++){
            f3 = f1+f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};