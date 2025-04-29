class Solution {
public:
    int n, m;
    vector<vector<int>> d_xy = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int i, int j, int& curArea, vector<vector<int>>& grid){
        grid[i][j] = 0; //marks as visited
        for(auto xy: d_xy){
            int adjr = i+xy[0];
            int adjc = j+xy[1];
            if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                if(grid[adjr][adjc] == 1){
                    curArea++;
                    dfs(adjr, adjc, curArea, grid);
                }
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int curArea = 1;
                    dfs(i, j, curArea, grid);
                    maxArea = max(curArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};