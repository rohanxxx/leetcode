class Solution {
public:
    int n, m;
    vector<vector<int>> dir;
    int dfs(int r, int c, int prevR, int prevC, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(prevR != -1 && matrix[r][c] <= matrix[prevR][prevC]) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        int path = 0;
        for(auto it: dir){
            int adjr = it[0]+r;
            int adjc = it[1]+c;
            if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                path = max(dfs(adjr, adjc, r, c, matrix, dp), path);
            }
        }

        return dp[r][c] = 1 + path;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int maxPath = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                maxPath = max(dfs(r, c, -1, -1, matrix, dp), maxPath);
            }
        }

        return maxPath;
    }
};