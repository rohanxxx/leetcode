class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose (matrix[0].size(),vector<int>(matrix.size(), 0));
        for(int r = 0; r < matrix[0].size(); r++){
            for(int c = 0; c < matrix.size(); c++){
                transpose[r][c] = matrix[c][r]; 
            }
        }
        return transpose;
    }
};