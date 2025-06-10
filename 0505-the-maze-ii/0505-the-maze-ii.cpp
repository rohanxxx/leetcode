class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        queue<vector<int>> q;
        q.push({start[0], start[1]});
        
        dist[start[0]][start[1]] = 0;

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int curDis = dist[r][c];

            q.pop();

            for(auto it: dir){
                int adjr = it[0] + r;
                int adjc = it[1] + c;
                int curStep = curDis;
                while(adjr >= 0 && adjc >= 0 && adjr < n && adjc < m && maze[adjr][adjc] == 0){
                    curStep++;
                    adjr += it[0];
                    adjc += it[1];
                }

                int prevRow = adjr - it[0];
                int prevCol = adjc - it[1];

                if(curStep < dist[prevRow][prevCol]){
                    dist[prevRow][prevCol] = curStep;
                    q.push({prevRow, prevCol});
                }
            }
        }

        if(dist[destination[0]][destination[1]] == INT_MAX) return -1;
        return dist[destination[0]][destination[1]];
    }
};