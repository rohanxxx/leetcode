/*
    [3, 0, 1, 4, 2]
    [5, 6, 3, 2, 1]
    [1, 2, 0, 1, 5]
    [4, 1, 0, 1, 7]
    [1, 0, 3, 0, 5]

     3,  3,  4,  8, 10
    15, 21, 24, 26, 27
    28, 30, 30, 31, 36
    40, 41, 41, 42, 49
    50, 50. 53, 53, 58
    
    3,  3,  4,  8, 10
    5, 11, 14, 16, 17
    1,  3,  3,  4,  9
    4,  5,  5,  6, 13
    1,  1,  4,  4,  9

     3, 0, 1, 4,  2
     8, 6, 4, 6,  3
     9, 8, 4, 7,  8
    13, 9, 4, 8, 15
    14, 9, 7, 8, 20

*/
/*
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
    }
};*/


class NumMatrix {
private:
    vector<vector<int>> sumMat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        //int COLS = ROWS ? matrix[0].size() : 0;
        
        int COLS = 0;
        if (ROWS) {
            COLS = matrix[0].size();
        } 

        // sumMat has an extra top row and left col (all zeros)
        sumMat.assign(ROWS + 1, vector<int>(COLS + 1, 0));
        /*
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                cout << sumMat[i][j] << " ";
            }
            cout << endl;
        }*/

        for (int r = 0; r < ROWS; ++r) {
            int prefix = 0;
            for (int c = 0; c < COLS; ++c) {
                prefix += matrix[r][c];                  // row running sum
                int above = sumMat[r][c + 1];            // sum up to cell above
                sumMat[r + 1][c + 1] = prefix + above;   // inclusive prefix sum
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        // shift to 1-based indices for padded matrix
        ++r1; ++c1; ++r2; ++c2;

        int bottomRight = sumMat[r2][c2];
        int above       = sumMat[r1 - 1][c2];
        int left        = sumMat[r2][c1 - 1];
        int topLeft     = sumMat[r1 - 1][c1 - 1];

        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */