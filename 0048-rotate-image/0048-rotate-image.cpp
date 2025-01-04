class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        for(int r = 0; r < row; r++){
            for(int c = r; c < column; c++){
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        for(int r = 0; r < row; r++){
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};