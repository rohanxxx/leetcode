class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool isCol = true;
        bool isRow = true;

        // check first row
        for(int c = 0; c < col; c++){
            if(matrix[0][c] == 0) {
                isCol = false;
                break;
            }
        }

        // check first col
        for(int r = 0; r < row; r++){
            if(matrix[r][0] == 0){
                isRow = false;
                break;
            }
        }

        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                if(matrix[r][c] == 0){
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // now make all the col's 0
        for(int c = 1; c < col; c++){
            if(matrix[0][c] == 0){
                for(int r = 1; r < row; r++) matrix[r][c] = 0;
            }
        }

        // now make all the row's 0
        for(int r = 1; r < row; r++){
            if(matrix[r][0] == 0){
                for(int c = 1; c < col; c++) matrix[r][c] = 0;
            }
        }

        if(isCol == false){
            for(int c = 0; c < col; c++) matrix[0][c] = 0;
        }

        if(isRow == false){
            for(int r = 0; r < row; r++) matrix[r][0] = 0;
        }
    }
};