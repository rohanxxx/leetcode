class Solution {
public:
    vector<int> map = {0,1,1};

    int dfs(int r, int c, vector<pair<int, int>>& moves, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if (k < 0) return INT_MIN;

        if (r == m-1 && c == n-1) {
            return grid[r][c];
        }

        if (dp[r][c][k] != -1) {
            return dp[r][c][k];
        }

        int maxRes = INT_MIN;

        for (auto it : moves) {
            int adjr = r + it.first;
            int adjc = c + it.second;

            if (adjr >= m || adjc >= n) continue;

            int cost = map[grid[adjr][adjc]];
            int res = dfs(adjr, adjc, moves, grid, k - cost, dp);

            if (res != INT_MIN) {
                maxRes = max(maxRes, res + grid[r][c]);
            }
        }

        return dp[r][c][k] = maxRes;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> moves = {{1,0}, {0,1}};

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(k+1, -1)));

        int startCost = map[grid[0][0]];
        int res = dfs(0, 0, moves, grid, k - startCost, dp);

        return res == INT_MIN ? -1 : res;
    }
};