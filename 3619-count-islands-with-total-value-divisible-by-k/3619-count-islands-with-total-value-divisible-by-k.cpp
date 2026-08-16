class Solution {
public:
    long long bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> direction = {
            {0,1},{1,0},{0,-1},{-1,0}
        };

        long long sum = 0;

        queue<pair<int, int>> q;
        
        q.push({i,j});
        visited[i][j] = 1;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int r = it.first;
            int c = it.second;

            sum += grid[r][c];

            for(auto pair: direction){
                int adjr = r+pair[0];
                int adjc = c+pair[1];

                if(adjr < 0 || adjc < 0 || adjr >= n || adjc >= m || visited[adjr][adjc] || grid[adjr][adjc] == 0){
                    continue;
                }

                q.push({adjr, adjc});
                visited[adjr][adjc] = 1;
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 1 || grid[i][j] == 0){
                    continue;
                }
                long long sum = bfs(i, j, grid, visited);
                if(sum % k == 0){
                    count++;
                }
            }
        }

        return count;
    }
};