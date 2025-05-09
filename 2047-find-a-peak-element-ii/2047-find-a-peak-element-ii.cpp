/*                  
                    1 4
                    3 2
                       0  1  2 
                    0 10 20 15
                    1 21 30 14
                    2 7  16 32

                    row*3+col/2 -> 2

                    5 - row = 1 and col = 2
                    col = 5 % colSize = 2
                    row = 5/colSize = 1

                    we can our left = 0 and right = n*m
                    then do a while loop to run it in condition like this 
*/
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int i = 0, j = col - 1;

        while (i >= 0 && i < row && j >= 0 && j < col) {
            int up, down, left, right;

            if (i - 1 < 0) up = -1;
            else up = mat[i - 1][j];

            if (i + 1 >= row) down = -1;
            else down = mat[i + 1][j];

            if (j - 1 < 0) left = -1;
            else left = mat[i][j - 1];

            if (j + 1 >= col) right = -1;
            else right = mat[i][j + 1];

            // check if current is a peak
            if (mat[i][j] > up && mat[i][j] > down && mat[i][j] > left && mat[i][j] > right)
                return {i, j};

            // find max among up, down, left, right
            int maxm = max(max(up, down), max(left, right));

            if (up == maxm)
                i--;
            else if (down == maxm)
                i++;
            else if (left == maxm)
                j--;
            else if (right == maxm)
                j++;
        }

        return {-1, -1};
    }
};