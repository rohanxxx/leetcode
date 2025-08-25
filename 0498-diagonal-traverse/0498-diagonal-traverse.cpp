class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        int i = 0, j = 0, dir = 0; // 0 = up-right, 1 = down-left

        for (int cnt = 0; cnt < n * m; ++cnt) {
            ans.push_back(mat[i][j]);

            if (dir == 0) { // moving up-right
                if (j == m - 1) {         // hit right wall: go down, flip
                    i++; dir = 1;
                } else if (i == 0) {      // hit top wall: go right, flip
                    j++; dir = 1;
                } else {                  // interior: go up-right
                    i--; j++;
                }
            } else { // dir == 1, moving down-left
                if (i == n - 1) {         // hit bottom wall: go right, flip
                    j++; dir = 0;
                } else if (j == 0) {      // hit left wall: go down, flip
                    i++; dir = 0;
                } else {                  // interior: go down-left
                    i++; j--;
                }
            }
        }
        return ans;
    }
};