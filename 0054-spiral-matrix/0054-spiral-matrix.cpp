class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row = matrix.size();
        int column = matrix[0].size();
        int left = 0, right = column-1;
        int up = 0, down = row-1;

        while(v.size() < row*column){
            // left to right
            for(int c = left; c <= right; c++) v.push_back(matrix[up][c]);
            // up to down
            for(int r = up+1; r <= down; r++) v.push_back(matrix[r][right]);
            // right to left
            if(up != down){
                for(int c = right-1; c >= left; c--) v.push_back(matrix[down][c]);
            }
            // down to up
            if(left != right){
                for(int r = down-1; r > up; r--) v.push_back(matrix[r][left]);
            }
            up++; down--;
            left++; right--;
        }
        return v;
    }
};