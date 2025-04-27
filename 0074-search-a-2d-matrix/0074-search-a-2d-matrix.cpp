class Solution {
public:
/*
    0 1 2  3
    4 5 6  7
    8 9 10 11

    n*m = 3*4 = 12
    left = 0, right = 12-1 = 11;
    mid = (0+11)/2 = 5
    row = 5/4 = 1
    col = 5%4 = 1
*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = n*m-1;
        while(left <= right){
            int midIndex = (left+right)/2;
            int r = midIndex / m;
            int c = midIndex % m;
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) left = midIndex+1;
            else right = midIndex-1;
        }
        return false;
    }
};