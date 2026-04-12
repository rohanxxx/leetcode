class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int totalKeyCount = 0;
        int n = grid.size(), m = grid[0].size();
        int startRow = -1, startCol = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c = grid[i][j];
                if(c == '@'){
                    startRow = i;
                    startCol = j;
                }
                if(c >= 'a' && c <= 'f'){
                    totalKeyCount++;
                }
            }
        }

        // queue: {steps, keyCount, row, col, k0,k1,k2,k3,k4,k5}
        queue<vector<int>> q;
        q.push({0,0,startRow,startCol,0,0,0,0,0,0});

        // visited state: row, col, keys
        set<vector<int>> visited;
        visited.insert({startRow, startCol, 0,0,0,0,0,0});

        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            vector<int> node = q.front(); q.pop();

            int step = node[0];
            int count = node[1];
            int r = node[2];
            int c = node[3];

            if(count == totalKeyCount){
                return step;
            }

            vector<int> keys(node.begin()+4, node.end());

            for(auto &d: dir){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                char ch = grid[nr][nc];
                if(ch == '#') continue;

                vector<int> newKeys = keys;
                int newCount = count;

                // LOCK
                if(ch >= 'A' && ch <= 'F'){
                    if(newKeys[ch - 'A'] == 0) continue;
                }

                // KEY
                if(ch >= 'a' && ch <= 'f'){
                    if(newKeys[ch - 'a'] == 0){
                        newKeys[ch - 'a'] = 1;
                        newCount++;
                    }
                }

                vector<int> state = {nr, nc};
                state.insert(state.end(), newKeys.begin(), newKeys.end());

                if(visited.find(state) == visited.end()){
                    visited.insert(state);

                    vector<int> temp = {step+1, newCount, nr, nc};
                    temp.insert(temp.end(), newKeys.begin(), newKeys.end());

                    q.push(temp);
                }
            }
        }

        return -1;
    }
};