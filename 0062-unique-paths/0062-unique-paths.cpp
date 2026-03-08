/*
    robot starting location -> top-left
    goal location -> bottom right

    moves -> down or right 2 moves
    2 integers given 

    return the possible unique paths that the robot can take to reach the goal state

    1 1 1 1   1  1  1
    1 2 3 4   5  6  7
    1 3 6 10 15 21 28

    
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
        //vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //return dfs(m, n, dp);

        vector<int> prev(n+1, 0);
        for(int r = 1; r <= m; r++){
            vector<int> cur(n+1, 0);
            for(int c = 1; c <= n; c++){
                if(r == 1 && c == 1){
                    cur[c] = 1;
                    continue;
                }
                int left = prev[c];
                int up = cur[c-1];
                cur[c] = left + up;
            }
            prev = cur;
        }

        return prev[n];
    }
};