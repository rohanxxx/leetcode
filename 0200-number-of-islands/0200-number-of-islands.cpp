class Solution {
public:
    int m, n;
    void vanishIslands(vector<vector<char>>& grid, int r, int c){
        if(grid[r][c] == '0') return;
        if(grid[r][c] == '1') grid[r][c] = '0';
        
        // up
        if((r-1) >= 0) vanishIslands(grid, r-1, c);
        // down
        if((r+1) < m) vanishIslands(grid, r+1, c); 
        // left
        if((c-1) >= 0) vanishIslands(grid, r, c-1);
        // right
        if((c+1) < n) vanishIslands(grid, r, c+1);
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