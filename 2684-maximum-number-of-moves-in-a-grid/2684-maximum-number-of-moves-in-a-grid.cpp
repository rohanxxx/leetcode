/*
 m*n matrix consisting of positive integer
 start can be any cell in the first col of the matrix
 traverse rules: (r-1,col+1)/, (r, c+1) ->, (r+1, c+1) \
 such that the value of the cell you move to should be strictly bigger than the value of the current cell

 return the max number of moves you can perform 

 Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
 Output: 3

 [2, 4, 3, 5]
 [5, 4, 9, 3]
 [3, 4, 2,11]
 [10,9,13,15]

 vector<vector<int>> moves = {{-1, 1}, {0, 1}, {1, 1}};

*/
class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int ret = 0;

        int m = grid.size();
        int n = grid[0].size();

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        vector<vector<int>> moves = {{-1, 1}, {0, 1}, {1, 1}};

        for(auto it: moves){
            int adjr = it[0]+r;
            int adjc = it[1]+c;
            if(adjr < 0 || adjr >= m || adjc < 0 || adjc >= n || grid[adjr][adjc] <= grid[r][c]){
                continue;
            }
            //otherwise move forward
            ret = max(ret, 1+dfs(adjr, adjc, grid, dp));
        }
        return dp[r][c] = ret;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        //O(N)
        for(int r = 0; r < m; r++){
            ans = max(ans, dfs(r, 0, grid, dp));
        }

        return ans;
    }
};