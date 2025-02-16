class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 3) return 2;
        if(n == 1 or n == 2) return 1;
        
        long val = n;
        // cout << "val: " << val << endl;
        for(long i = 1; i < n; i++){
            if(i > val) return i-1;
            val -= (long)i;
            // cout << "val: " << val << endl;
        }
        return n;
    }
};