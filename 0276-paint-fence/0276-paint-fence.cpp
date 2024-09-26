class Solution {
private:
    unordered_map<int, int> memo;
    int totalWays(int i, int k){
        if(i == 1) return k;
        if(i == 2) return k*k;

        if(memo.find(i) != memo.end()) return memo[i];

        memo[i] = (k-1) * (totalWays(i-1, k)+totalWays(i-2, k));

        return memo[i];
    }

public:
    int numWays(int n, int k) {
        return totalWays(n,k);
    }
};