class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dis(n, vector<int>(m, 0));
        
        int d = 0;
        vector<vector<int>> coord = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                for(int j = 0; j < 4; j++){
                    int R = r + coord[j][0];
                    int C = c + coord[j][1];
                    if(R >= 0 && R < n && C >= 0 && C < m && visited[R][C] == false){
                        visited[R][C] = true;
                        q.push({R,C});
                    }
                }
                dis[r][c] = d;
            }
            d++;
        }
        return dis;
    }
};