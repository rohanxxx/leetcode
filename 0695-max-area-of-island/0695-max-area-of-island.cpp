class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCount = 0;

        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while(!q.empty()){
                        count++;
                        int r = q.front().first;
                        int c = q.front().second;
                        
                        q.pop();

                        for(auto it: dir){
                            int adjr = it.first + r;
                            int adjc = it.second + c;
                            if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                                if(grid[adjr][adjc] == 1){
                                    grid[adjr][adjc] = 0;
                                    q.push({adjr, adjc});
                                }
                            }
                        }
                    }
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};