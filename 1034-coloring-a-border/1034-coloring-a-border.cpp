class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<vector<int>> q;
        
        q.push({row, col});
        visited[row][col] = 1;

        vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
        vector<vector<int>> border;

        while(!q.empty()){
            int cur_row = q.front()[0];
            int cur_col = q.front()[1];

            q.pop();

            bool isBorder = false;

            for(auto it: dir){
                int adjr = it[0] + cur_row;
                int adjc = it[1] + cur_col;

                if(adjr < 0 || adjc < 0 || adjr >= n || adjc >= m){
                    isBorder = true;
                    continue;
                }

                if(grid[adjr][adjc] != grid[cur_row][cur_col]){
                    isBorder = true;
                    continue;
                }

                if(visited[adjr][adjc] == 0){
                    q.push({adjr, adjc});
                    visited[adjr][adjc] = 1;
                }
            }

            //check if it is a border
            if(isBorder){
                border.push_back({cur_row, cur_col});
            }
        }

        for(auto& cell : border){
            grid[cell[0]][cell[1]] = color;
        }

        return grid;
    }
};