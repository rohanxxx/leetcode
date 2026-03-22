class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m-1;

        while(r >= 0 && r < n && c >= 0 && c < m){
            if(target < matrix[r][c]){
                c = c-1;
            }
            else if(target > matrix[r][c]){
                r = r+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};