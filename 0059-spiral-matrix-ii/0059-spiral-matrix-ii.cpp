/*
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

1 2 3
8 9 4
7 6 5

  0  1  2  3
0 1  2  3  4
1 12 13 14 5
2 11 16 15 6
3 10 9  8  7

left -> right
up -> down
right -> left
down -> up
*/
class Solution {
public:
    //TC: O(N+N) = O(2N) = O(N)
    //SC: O(1)
    vector<vector<int>> generateMatrix(int n) {
        //TC: O(N)
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        int left = 0, right = n-1;
        int up = 0, down = n-1;

        int count = 0;
        //TC: O(N)
        //SC: O(1)
        while(count <= n*n-1){
            //left to right
            for(int i = left; i <= right; i++){
                grid[up][i] = ++count;
            }
            //up to down
            for(int i = up+1; i <= down; i++){
                grid[i][right] = ++count;
            }
            //right to left
            for(int i = right-1; i >= left; i--){
                grid[down][i] = ++count;
            }
            //down to up
            for(int i = down-1; i >= up+1; i--){
                grid[i][left] = ++count;
            }
            left++; up++;
            right--; down--;
        }

        return grid;
    }
};