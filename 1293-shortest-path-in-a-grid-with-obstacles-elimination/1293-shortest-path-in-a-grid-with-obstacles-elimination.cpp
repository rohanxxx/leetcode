class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));

        queue<vector<int>> q;

        if(grid[0][0] == 0){
            q.push({0,0,0,k});
            visited[0][0][k] = true;
        }
        else if(grid[0][0] == 1 && k > 0){
            q.push({0,0,0,k-1});
            visited[0][0][k-1] = true;
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            auto it = q.front(); q.pop();

            int r = it[0];
            int c = it[1];
            int step = it[2];
            int currK = it[3];

            if(r == n-1 && c == m-1){
                return step;
            }

            for(auto d: dir){
                int adjr = r + d.first;
                int adjc = c + d.second;

                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m){
                    continue;
                }

                // blocked
                if(grid[adjr][adjc] == 1 && currK > 0){
                    if(!visited[adjr][adjc][currK-1]){
                        q.push({adjr, adjc, step+1, currK-1});
                        visited[adjr][adjc][currK-1] = true;
                    }
                }

                // free
                if(grid[adjr][adjc] == 0){
                    if(!visited[adjr][adjc][currK]){
                        q.push({adjr, adjc, step+1, currK});
                        visited[adjr][adjc][currK] = true;
                    }
                }
            }
        }

        return -1;
    }
};