class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int orangeCount = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    continue;
                }
                if(grid[i][j] == 1){
                    orangeCount++;
                }
            }
        }
        //cout << "orangeCount: " << orangeCount << endl;
        vector<vector<int>> d_xy = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int time = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                orangeCount--;
                pair<int, int> p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                for(auto xy: d_xy){
                    int curRow = r + xy[0];
                    int curCol = c + xy[1];
                    if(curRow >= 0 && curRow < n && curCol >= 0 && curCol < m){
                        if(grid[curRow][curCol] == 1){
                            grid[curRow][curCol] = 2;
                            q.push({curRow, curCol});
                        }
                    }
                }
            }
            time++;
        }
        //cout << "orangeCount: " << orangeCount << endl;
        //if(orangeCount > 0) return -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        if(time == -1) return 0;
        return time;
    }
};