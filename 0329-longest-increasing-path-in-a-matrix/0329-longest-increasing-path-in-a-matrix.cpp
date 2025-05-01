class Solution {
public:
    int m, n;
    vector<vector<int>>dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache){
        if(cache[i][j] != 0) return cache[i][j];
        for(int k = 0; k < dir.size(); k++){
            int x = i+dir[k][0], y = j+dir[k][1];
            if(0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = max(cache[i][j], dfs(matrix, x, y, cache));
        }
        return ++cache[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return 0;
        
        n = matrix[0].size();

        vector<vector<int>> cache(m, vector<int>(n,0));
        int longest_path = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                longest_path = max(longest_path, dfs(matrix, i, j, cache));
        return longest_path;
    }
};