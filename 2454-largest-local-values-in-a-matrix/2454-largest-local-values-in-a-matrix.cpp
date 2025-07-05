class Solution {
public:
    int n;
    int findMaxLocal(int& x, int& y, vector<vector<int>>& grid){
        int maxLocal = INT_MIN;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                maxLocal = max(maxLocal, grid[i][j]);
            }
        }
        return maxLocal;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        //O((N-2) * (N-2))
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                //O(3*3) = O(9)
                ans[i][j] = findMaxLocal(i, j, grid);
            }
        }

        return ans;
    }
};