class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int size = n*m;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int key = i * m + j;
                int newKey = (key + k)%size;
                int new_i = newKey / m;
                int new_j = newKey % m;
                ans[new_i][new_j] = grid[i][j];
            }
        }

        return ans;
    }
};