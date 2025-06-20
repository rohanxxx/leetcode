/*
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13

     0 1 2
    [2,1,3]
    [6,5,4]
    [7,8,9]
*/
class Solution {
public:
    int n;
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        //base case
        if(c < 0 || c >= n){
            return INT_MAX;
        }

        if(r == n-1){
            return matrix[r][c];
        }

        if(dp[r][c] != INT_MAX){
            return dp[r][c];
        }

        int take1, take2, take3;
        //bottom
        take1 = dfs(r+1, c, matrix, dp);
        //bottom-left
        take2 = dfs(r+1, c-1, matrix, dp);
        //bottom-right
        take3 = dfs(r+1, c+1, matrix, dp);

        return dp[r][c] = matrix[r][c] + min({take1, take2, take3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        //write up a for loop
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++){
            minSum = min(dfs(0, i, matrix, dp), minSum);
        }
        return minSum;
    }
};