/*
  ["a","a","a","a"]
  ["a","b","a","a"]
  ["a","b","a","a"]
  ["a","a","a","a"]
*/
class Solution {
public:
    bool detectCycle(pair<int,int>& parent, pair<int, int>& curr, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[curr.first][curr.second] = true;
        
        queue<vector<int>> q;
        q.push({parent.first, parent.second, curr.first, curr.second});
        
        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int pr = it[0];
            int pc = it[1];
            int r = it[2];
            int c = it[3];

            for(auto neighbor: dir){
                int adjr = neighbor.first + r;
                int adjc = neighbor.second + c;

                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m){
                    continue;
                }
                //if not same node no need to go further for traversal
                if(grid[adjr][adjc] != grid[r][c]){
                    continue;
                }

                //if not visited then push
                if(visited[adjr][adjc] == 0){
                    q.push({r,c,adjr,adjc});
                    visited[adjr][adjc] = 1;
                }
                //otherwise visited & not equal to parent
                else if(adjr != pr || adjc != pc){
                    return true; //detects cycle
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 0){
                    pair<int,int> parent = {-1, -1};
                    pair<int,int> curr = {i,j};
                    if(detectCycle(parent, curr, visited, grid) == true){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};