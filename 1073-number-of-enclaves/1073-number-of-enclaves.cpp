/*
    1 -> land
    0 -> sea
    4 directional moves

    Return the number of land cells in grid for which 
    we cannot walk off the boundary of the grid in any number of moves.

    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    [0,0,0,0]
    [1,0,1,0]
    [0,1,1,0]
    [0,0,0,0]


*/
class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    //implement bfs
    void bfs(int r, int c, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        //later
        queue<pair<int, int>> q;
        q.push({r,c});
        grid[r][c] = 0;

        //bfs search
        while(!q.empty()){
            int curRow = q.front().first;
            int curCol = q.front().second;

            q.pop();

            //we do 4 directional search
            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                //check if it goes out of bounds
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(grid[adjr][adjc] == 1){
                        grid[adjr][adjc] = 0;
                        q.push({adjr, adjc});
                    }
                }
            }
        }

        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //first iteration we just find the lands that can be walked of the boundary
        //O(N*M)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        //marks the land that are connected to the boundary
                        bfs(i, j, grid);
                    }
                }
            }
        }

        int countLandCells = 0;
        //now we count the land cells with 1
        //traversing the matrix one more time
        //TC: O(N*M)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    countLandCells++;
                }
            }
        }

        return countLandCells;
    }
};