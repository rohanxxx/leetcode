/*
    0 1 0
    1 0 1

    [1,0]
    [0,0]
*/
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int maxRow, minRow, maxCol, minCol;
        maxRow = maxCol = INT_MIN;
        minRow = minCol = INT_MAX;

        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                    maxCol = max(maxCol, j);
                    minCol = min(minCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};