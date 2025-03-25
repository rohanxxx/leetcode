class Solution {
public:
    int func(int i, int j1, int j2, int& r, int& c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){
            return INT_MIN;
        }
        if(i == r-1){
            if(j1 == j2) return dp[i][j1][j2] = grid[i][j1];
            return dp[i][j1][j2] = grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }

        for(int dl1 = -1; dl1 <= 1; dl1++){
            for(int dl2 = -1; dl2 <= 1; dl2++){
                int sum = 0;
                
                if(j1 == j2) sum = grid[i][j1];
                else sum = grid[i][j1] + grid[i][j2]; 
                
                int val = func(i+1, j1+dl1, j2+dl2, r, c, grid, dp);
                if(val == INT_MIN) val = 0;

                dp[i][j1][j2] = max(dp[i][j1][j2], sum+val);
            }
        }
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return func(0, 0, m-1, n, m, grid, dp);
    }
};