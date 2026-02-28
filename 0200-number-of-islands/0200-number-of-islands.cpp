class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    void bfs(int r, int c, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q; q.push({r,c});
        while(!q.empty()){
            int curRow = q.front()[0];
            int curCol = q.front()[1];
            q.pop();
            for(auto d: dir){
                int adjr = d[0]+curRow;
                int adjc = d[1]+curCol;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(grid[adjr][adjc] == '1'){
                        //marks visited
                        grid[adjr][adjc] = '0';
                        q.push({adjr, adjc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    //marks as visited
                    grid[i][j] = '0';
                    bfs(i, j, grid);
                }
            }
        }

        return count;
    }
};