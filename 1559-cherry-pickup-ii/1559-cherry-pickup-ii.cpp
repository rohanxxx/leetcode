class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        //our one of the primary base case is ready
        //tc O(M*M) + O(N*M*M*9)
        //sc 0(N*M*M) -> improve the space complexity to O(M*M); 
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        //O(N*M*M*9)
        for(int i = n-2; i >= 0; i--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    for(int dl1 = -1; dl1 <= 1; dl1++){
                        for(int dl2 = -1; dl2 <= 1; dl2++){
                            int val;
                            
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2]; 
                            
                            if(j1+dl1 < 0 || j1+dl1 >= m || j2+dl2 < 0 || j2+dl2 >= m){
                                val = INT_MIN;
                            }
                            else{
                                val += dp[i+1][j1+dl1][j2+dl2];
                            }
                            dp[i][j1][j2] = max(dp[i][j1][j2], val);
                        }
                    }
                    //dp[i][j1][j2];
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};