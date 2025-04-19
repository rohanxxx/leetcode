class Solution {
public:
    int m, n;
    void vanishIslands(vector<vector<char>>& grid, int r, int c){
        if(grid[r][c] == '0') return;
        grid[r][c] = '0';
        vector<vector<int>> cood = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < cood.size(); i++){
            int R = r+cood[i][0];
            int C = c+cood[i][1];
            if(R >= 0 && R < grid.size() && C >= 0 && C < grid[0].size()){
                vanishIslands(grid, R, C);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    vanishIslands(grid, i, j);
                }
            }
        }

        return count;
    }
};