class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ops = 0;
        for(int j = 0; j < col; j++){
            int target = grid[0][j]+1;
            for(int i = 1; i < row; i++){
                if(grid[i][j] < target){
                    ops += (target-grid[i][j]);
                    target = grid[i][j]+(target-grid[i][j])+1;
                }
                else{
                    target = grid[i][j]+1;
                }
            }
        }

        return ops;
    }
};