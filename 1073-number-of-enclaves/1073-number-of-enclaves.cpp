class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) count++;
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        q.push({i,j});
                    }
                }
            }
        }

        vector<vector<int>> coord = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            count--;
            pair<int, int> p = q.front(); q.pop();
            int r = p.first;
            int c = p.second;
            for(int i = 0; i < 4; i++){
                int R = r+coord[i][0];
                int C = c+coord[i][1];
                if(R >= 0 && R < n && C >= 0 && C < m && grid[R][C] == 1){
                    grid[R][C] = 0;
                    q.push({R, C});
                }
            }
        }

        return count;
    }
};