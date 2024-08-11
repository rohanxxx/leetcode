class Solution {
private: 
    vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int backtracking(vector<vector<int>>& grid, int r, int c, int& rows, int& cols){
        if(r < 0 || c < 0 || r == rows || c == cols) return 0;
        if(grid[r][c] == 0) return 0;

        int maxGold = 0;
        int originalValue = grid[r][c];
        
        grid[r][c] = 0;
        for(int i = 0; i < this->d.size(); i++){
            maxGold = max(maxGold, backtracking(grid, r + this->d[i][0], c + this->d[i][1], rows, cols));
        }
        grid[r][c] = originalValue;

        return originalValue+maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                maxGold = max(maxGold, backtracking(grid, r, c, rows, cols));
            }
        }

        return maxGold;
    }
};