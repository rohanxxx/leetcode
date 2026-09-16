/*

    [3,0,8,4]
    [2,4,5,7]
    [9,2,6,3]
    [0,3,1,0]

    [8,4,8,7]
    [7,4,7,7]
    [9,4,8,7]
    [3,3,3,3]

    N -> 9 4 8 7
    S -> 9 4 8 7
    E -> 8 7 9 3
    W -> 8 7 9 3
*/
class Solution {
public:
    /*int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> verticalView(row, 0);
        vector<int> horizontalView(col, 0);

        for(int j = 0; j < col; j++){
            for(int i = 0; i < row; i++){
                verticalView[i] = max(verticalView[i], grid[i][j]);
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                horizontalView[i] = max(horizontalView[i], grid[i][j]);
            }
        }

        int sum = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int maxVal = min(verticalView[j], horizontalView[i]);
                if(maxVal-grid[i][j] >= 0){
                    sum += (maxVal-grid[i][j]);
                }
            }
        }

        return sum;
    }*/
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> rowMax(row, 0);  // max of each row
        vector<int> colMax(col, 0);  // max of each column

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int sum = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                sum += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }

        return sum;
    }
};
