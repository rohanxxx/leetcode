/*
    [1,2,3,1]
    [4,5,6,1]
    [7,8,9,1]
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));

        queue<vector<int>> q;

        for(int i = 0; i < m; i++){
            q.push({grid[0][i], 0, i});
            cost[0][i] = grid[0][i];
        }

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int sum = it[0];
            int r = it[1];
            int c = it[2];

            
            int adjr = r+1;
            if(adjr >= n || sum > cost[r][c]) continue;
            //traverse through all the colomuns
            for(int adjc = 0; adjc < m; adjc++){
                if(c == adjc) continue;
                int newSum = sum + grid[adjr][adjc];
                if(newSum >= cost[adjr][adjc]) continue;

                //otherwise
                q.push({newSum, adjr, adjc});
                cost[adjr][adjc] = newSum;
            }

        }

        int minPathSum = INT_MAX;
        for(int c = 0; c < m; c++){
            minPathSum = min(minPathSum, cost[n-1][c]);
        }

        return minPathSum;
    }
};