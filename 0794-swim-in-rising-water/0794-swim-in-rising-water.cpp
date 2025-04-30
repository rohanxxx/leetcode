class Solution {
public:
    /*
        6, 17, 18, 19, 20, 21, 22, 23, 24
    */
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        //{value, {r, c}}
        //pair<int, pair<int, int>>;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0,0}});
        //mark that as visited
        visited[0][0] = 1;
        int maxSoFar = INT_MIN;
        while(!pq.empty()){
            int time = pq.top().first;
            int curRow = pq.top().second.first;
            int curCol = pq.top().second.second;

            pq.pop();
            
            //this is where we caputre our desired solution
            maxSoFar = max(maxSoFar, time);
            if(curRow == n-1 && curCol == m-1){
                return maxSoFar;
            }

            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(visited[adjr][adjc] == 0){
                        visited[adjr][adjc] = 1;
                        pq.push({grid[adjr][adjc], {adjr, adjc}});
                    }
                }
            }
        }

        return maxSoFar;
    }
};