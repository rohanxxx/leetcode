/*
    n = 5
    1+1+1+1+1 = 5 ->5
    1+2+1+1 = 5 -> 2
    1+2+2 = 5 -> 4
    1+3+1 = 5 -> 3
    2+3 = 5 -> 6
*/
class Solution {
public:
    int dfs(int sum, long long curProduct, int& n, unordered_map<string, int>& dp){
        if(sum > n) return INT_MIN;
        if(sum == n) return curProduct;

        string key = to_string(sum)+"#"+to_string(curProduct);

        if(dp.count(key)) return dp[key];

        int result = INT_MIN;
        for(int i = 1; i < n; i++){
            if(sum == 0) result = max(dfs(sum+i, (long long)i, n, dp), result);
            else result = max(dfs(sum+i, (long long)i*curProduct, n, dp), result);
        }
        return dp[key] = result;
    }
    int integerBreak(int n) {
        unordered_map<string, int> dp;
        return dfs(0, 1, n, dp);
    }
};