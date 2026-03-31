class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto it: dir){
                int adjr = it.first+r;
                int adjc = it.second+c;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(rooms[adjr][adjc] == -1){
                        continue;
                    }
                    if(rooms[r][c]+1 < rooms[adjr][adjc]){
                        q.push({adjr, adjc});
                        rooms[adjr][adjc] = rooms[r][c]+1;
                    }
                }
            }
        }
    }
};