/*
      0 1 2
    0[1,2,3]
    1[4,5,6]
    2[7,8,9]

    1st iteration: (0,0) -> {(0,1),(1,0)} -> {(0,2),(2,0)}
    2nd iteration: (0+1, 0+1) -> {1,1} -> {1,2}{2,1}
    3rd iteration: (1+1, 1+1)

    7 4 1
    8 5 2
    9 6 3

    1 4 7.    1 4 7.   7 4 1
    2 5 8.    2 5 8 -> 8 5 2
    3 6 9.    3 6 9.   9 6 3
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //TC: O(1)
        //n*n matrix
        int n = matrix.size();
        //TC: O(N*N)
        //horizontal to vertical
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int tr = j;
                int tc = i;
                swap(matrix[i][j], matrix[tr][tc]);
            }
        }

        //TC: O(N*N)
        //now we reverse each row
        for(int i = 0; i < n; i++){
            //TC: O(N)
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};