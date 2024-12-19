class Solution {
public:

    void vanishIsland(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] == '1'){

            grid[row][col] = '0';
            
            //checking up
            if(row-1 > -1) vanishIsland(grid, row-1, col);
            //checking down
            if(row+1 < grid.size()) vanishIsland(grid, row+1, col);
            //checking left
            if(col-1 > -1) vanishIsland(grid, row, col-1);
            //checking right
            if(col+1 < grid[row].size()) vanishIsland(grid, row, col+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        // vector<vector<char>> grid_copy = grid;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    vanishIsland(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};