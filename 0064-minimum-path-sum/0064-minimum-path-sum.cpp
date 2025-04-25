class Solution {
public:
int func(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
	if(r == 0 && c == 0) return grid[r][c];
	if(r < 0 || c < 0) return INT_MAX;
	
	if(dp[r][c] != -1) return dp[r][c];
	
//r, c-1
	//r-1, c
	int left = func(r, c-1, grid, dp);
	int up = func(r-1, c, grid, dp);
	int curPathSum = grid[r][c] + min(left, up);
	return dp[r][c] = curPathSum;
}


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return func(m-1, n-1, grid, dp);

    }
};