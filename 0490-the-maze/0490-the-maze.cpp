class Solution {
public:
    bool dfs(int rowSize, int colSize, vector<vector<int>>& maze, vector<int> curr, vector<int>& destination, vector<vector<bool>>& visit){
        if(visit[curr[0]][curr[1]]) return false;
        if(curr[0] == destination[0] && curr[1] == destination[1]) return true;
        visit[curr[0]][curr[1]] = true;
        vector<vector<int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0; i < 4; i++){
            int r = curr[0], c = curr[1];
            while(r >= 0 && r < rowSize && c >= 0 && c < colSize && maze[r][c] == 0){
                r += directions[i][0];
                c += directions[i][1];
            }
            if(dfs(rowSize, colSize, maze, {r-directions[i][0], c-directions[i][1]}, destination, visit)) return true;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rowSize = maze.size();
        int colSize = maze[0].size();
        vector<vector<bool>> visit(rowSize, vector<bool>(colSize));
        return dfs(rowSize, colSize, maze, start, destination, visit);
    }
};