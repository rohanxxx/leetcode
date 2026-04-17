class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        unordered_set<string> visitedState;
        int n = grid.size(), m = grid[0].size();
        
        queue<vector<int>> q;
        if(grid[0][0] == 0){
            q.push({0,0,0,k});
            string key = string("#"+to_string(0)+"#"+to_string(0)+"#"+to_string(k));
            visitedState.insert(key);
        }
        if(grid[0][0] == 1 && k > 0){
            q.push({0,0,0,k-1});
            string key = string("#"+to_string(0)+"#"+to_string(0)+"#"+to_string(k-1));
            visitedState.insert(key);
        }

        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int r = it[0];
            int c = it[1];
            int step = it[2];
            int currK = it[3];

            if(r == n-1 && c == m-1){
                return step;
            }

            for(auto d: dir){
                int adjr = r + d.first;
                int adjc = c + d.second;
                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m){
                    continue;
                }
                //if blocked
                if(grid[adjr][adjc] == 1 && currK > 0){
                    string key = string("#"+to_string(adjr)+"#"+to_string(adjc)+"#"+to_string(currK-1));
                    //if not found
                    if(visitedState.find(key) == visitedState.end()){
                        q.push({adjr, adjc, step+1, currK-1});
                        visitedState.insert(key);
                    }
                }
                //if not blocked
                if(grid[adjr][adjc] == 0){
                    string key = string("#"+to_string(adjr)+"#"+to_string(adjc)+"#"+to_string(currK));
                    if(visitedState.find(key) == visitedState.end()){
                        q.push({adjr, adjc, step+1, currK});
                        visitedState.insert(key);
                    }
                }
            }
        }

        return -1;
    }
};