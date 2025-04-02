class Solution {
public:
    int func(int index, int& k, int& n, vector<int>& arr, vector<int>& dp){
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
        int maxi = INT_MIN;
        int len = 0, maxElement = INT_MIN;
        for(int i = index; i < min(n, index+k); i++){
            len++;
            maxElement = max(arr[i], maxElement);
            int sum = maxElement*len + func(i+1, k, n, arr, dp);
            maxi = max(maxi, sum);
        }
        return dp[index] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return func(0, k, n, arr, dp);
    }
};