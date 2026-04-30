class Solution {
public:
    vector<int> map = {0,1,1};

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> moves = {{1,0}, {0,1}};

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN))
        );

        for(int r = m-1; r >= 0; r--){
            for(int c = n-1; c >= 0; c--){
                for(int i = 0; i <= k; i++){

                    if (r == m-1 && c == n-1) {
                        dp[r][c][i] = grid[r][c];
                        continue;
                    }

                    int maxRes = INT_MIN;

                    for (auto it : moves) {
                        int adjr = r + it.first;
                        int adjc = c + it.second;

                        if (adjr >= m || adjc >= n) continue;

                        int cost = map[grid[adjr][adjc]];
                        if(i - cost < 0) continue;

                        int res = dp[adjr][adjc][i - cost];

                        if (res != INT_MIN) {
                            maxRes = max(maxRes, res + grid[r][c]);
                        }
                    }

                    dp[r][c][i] = maxRes;
                }
            }
        }

        int startCost = map[grid[0][0]];

        int res = -1;
        for(int i = startCost; i <= k; i++){
            if(dp[0][0][i] != INT_MIN){
                res = max(res, dp[0][0][i]);
            }
        }

        return res;
    }
};