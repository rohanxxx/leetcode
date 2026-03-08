/*
    robot starting location -> top-left
    goal location -> bottom right

    moves -> down or right 2 moves
    2 integers given 

    return the possible unique paths that the robot can take to reach the goal state

    1 0 0 0 0 0 0
    0 0 0 0 0 0 0
    0 0 0 0 0 0 0

    
*/
class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& dp){
        if(r == 0 || c == 0) return 0;
        if(r == 1 && c == 1) return 1;

        if(dp[r][c] != 0) return dp[r][c];

        int left = dfs(r-1, c, dp);
        int up = dfs(r, c-1, dp);

        return dp[r][c] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //return dfs(m, n, dp);

        for(int r = 1; r <= m; r++){
            for(int c = 1; c <= n; c++){
                if(r == 1 && c == 1){
                    dp[r][c] = 1;
                    continue;
                }
                int left = dp[r-1][c];
                int up = dp[r][c-1];
                dp[r][c] = left + up;
            }
        }

        return dp[m][n];
    }
};