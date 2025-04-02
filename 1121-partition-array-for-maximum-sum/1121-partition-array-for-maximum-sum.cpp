class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int index = n-1; index >= 0; index--){
            int maxi = INT_MIN;
            int len = 0, maxElement = INT_MIN;
            for(int i = index; i < min(n, index+k); i++){
                len++;
                maxElement = max(arr[i], maxElement);
                int sum = maxElement*len + dp[i+1];
                maxi = max(maxi, sum);
            }
            dp[index] = maxi;
        }
        return dp[0];
    }
};