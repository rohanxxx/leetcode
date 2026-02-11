class Solution {
public:
    int n, m;
    vector<vector<int>> dir;

    int dfs(int r, int c, int prevR, int prevC, vector<vector<int>>& matrix, vector<vector<int>>& cache) {

        // invalid move (must be strictly increasing compared to previous cell)
        if (prevR != -1 && matrix[r][c] <= matrix[prevR][prevC]) return 0;

        // memo: longest path starting at (r,c) depends only on (r,c)
        if (cache[r][c] != 1) return cache[r][c];

        int bestFromNeighbors = 0;
        for (auto &it : dir) {
            int adjr = it[0] + r;
            int adjc = it[1] + c;
            if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m) {
                bestFromNeighbors = max(bestFromNeighbors, dfs(adjr, adjc, r, c, matrix, cache));
            }
        }

        // overwrite (don't accumulate)
        return cache[r][c] = cache[r][c] + bestFromNeighbors;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> cache(n, vector<int>(m, 1));

        int maxPath = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                maxPath = max(dfs(r, c, -1, -1, matrix, cache), maxPath);
            }
        }
        
        return maxPath;
    }
};