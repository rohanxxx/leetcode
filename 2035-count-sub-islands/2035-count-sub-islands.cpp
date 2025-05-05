class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int countSubIslands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && visited[i][j] == 0){
                    queue<pair<int, int>> q;
                    if(grid1[i][j] == 1 && grid2[i][j] == 1){
                        int flag = true;
                        q.push({i,j});
                        visited[i][j] = 1;
                    
                        while(!q.empty()){
                            int curRow = q.front().first;
                            int curCol = q.front().second;
                            q.pop();
                            for(auto it: dir){
                                int adjr = curRow+it[0];
                                int adjc = curCol+it[1];
                                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                                    if(grid2[adjr][adjc] == 1 && visited[adjr][adjc] == 0){
                                        q.push({adjr, adjc});
                                        visited[adjr][adjc] = 1;
                                        if(grid1[adjr][adjc] == 0 && grid2[adjr][adjc] == 1) {
                                            flag = false;
                                        }
                                    }
                                }
                            }
                        }

                        if(flag == true){
                            countSubIslands++;
                        }
                    }
                }
            }
        }
        return countSubIslands;
    }
};