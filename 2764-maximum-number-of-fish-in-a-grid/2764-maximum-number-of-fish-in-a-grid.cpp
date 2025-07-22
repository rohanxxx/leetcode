class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void bfs(int i, int j, int& maxSum, vector<vector<int>>& grid){
        int curSum = grid[i][j];
        maxSum = max(curSum, maxSum);

        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        q.push({i,j});

        //mark visited;
        grid[i][j] = 0;

        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            q.pop();

            for(auto& it: dir){
                int adjr = it[0]+r;
                int adjc = it[1]+c;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(grid[adjr][adjc] > 0){
                        curSum += grid[adjr][adjc];
                        
                        maxSum = max(curSum, maxSum);
                        
                        q.push({adjr, adjc});
                        grid[adjr][adjc] = 0;
                    }
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        //bfs technique

        int n = grid.size();
        int m = grid[0].size();

        int maxSum = 0;
        //start traversing and while on the way 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    bfs(i, j, maxSum, grid);
                }
            }
        }
        return maxSum;
    }
};