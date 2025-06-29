class Solution {
public:
    int dfs(int k, int n){
        while(n != 0 && n % k == 0){
            n = n/k;
        }
        return n;
    }
    bool isUgly(int n) {
        if(n == 0) return false;
        
        for(auto it: {2,3,5}){
            n = dfs(it, n);
        }

        if(n == 1 || n == 0) return true;
        if(n > 1) return false;

        return false;
    }
};