class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int c = 0; c < col; c++){
            dp[0][c] = matrix[0][c];
            sum += dp[0][c];
        }
        for(int r = 1; r < row; r++){
            dp[r][0] = matrix[r][0];
            sum += dp[r][0];
        }
        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                if(matrix[r][c] == 1){
                    dp[r][c] = 1 + min({dp[r][c-1], dp[r-1][c], dp[r-1][c-1]});
                    sum += dp[r][c];
                }
            }
        }
        return sum;
    }
};