class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int r = 0; r < matrix.size(); r++){
            for(int c = r; c < matrix[r].size(); c++){
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for(int r = 0; r < matrix.size(); r++){
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};