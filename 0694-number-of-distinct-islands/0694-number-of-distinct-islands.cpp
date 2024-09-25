class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    string currentIsland;

    void dfs(int row, int col, char dir){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return;
        if(visited[row][col] || grid[row][col] == 0) return;
        
        visited[row][col] = true;
        currentIsland += dir;

        dfs(row+1, col, 'D');
        dfs(row-1, col, 'U');
        dfs(row, col+1, 'R');
        dfs(row, col-1, 'L');

        currentIsland += '0';

        return;
    }

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        this->grid = grid;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        unordered_set<string> islands;

        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                currentIsland.clear();
                dfs(row, col, '0');
                if(!currentIsland.empty()){
                    islands.insert(currentIsland);
                }
            }
        }

        return islands.size();
    }
};