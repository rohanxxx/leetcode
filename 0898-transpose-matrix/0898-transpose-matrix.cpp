class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transposeMatrix (matrix[0].size(),vector<int>(matrix.size(), 0));
        for(int r = 0; r < matrix[0].size(); r++){
            for(int c = 0; c < matrix.size(); c++){
                transposeMatrix[r][c] = matrix[c][r]; 
            }
        }
        return transposeMatrix;
    }
};