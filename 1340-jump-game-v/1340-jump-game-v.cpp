/* 
    i+x < n and 0 < x <= d
    i-x >= 0 and 0 < x <= d

    u can jump i to index j arr[i] > arr[j] and arr[i] > arr[k]
    for all indices k between i and j

    you can choose any index of arr and start jumping, 
    return the maximum number of indices you can visit
           0 1 2. 3 4 5. 6 7 8  9 10
    arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2

*/
class Solution {
public:
    int dfs(int i, int d, vector<int>& arr, vector<int>& dp){
        if(dp[i] != -1){
            return dp[i];
        }

        int n = arr.size();
        int ans = 0;
        for(int j = i+1; j < min(i+d+1, n); j++){
            if(arr[i] <= arr[j]){
                break;
            }
            ans = max(ans, 1+dfs(j, d, arr, dp));
        }
        for(int j = i-1; j >= max(i-d, 0); j--){
            if(arr[i] <= arr[j]){
                break;
            }
            ans = max(ans, 1+dfs(j, d, arr, dp));
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            vector<int> dp(n, -1);
            ans = max(ans, 1+dfs(i, d, arr, dp));
        }

        return ans;
    }
};