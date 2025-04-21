class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }
        
        //curRow * totalCol + curCol
        vector<int> distance(n*m, INT_MAX);

        // {0,0,1}
        // first zero is the row
        // second zero is the col
        // third element is the distance to get to that particular vector
        queue<vector<int>> q; q.push({0,0,1});
        distance[0] = 1;

        vector<vector<int>> deltaXY = {{-1, -1}, {-1, 1}, {1,-1}, {1,1}, {0,-1}, {0,1}, {-1, 0}, {1, 0}};
        while(!q.empty()){
            vector<int> v = q.front(); q.pop();
            int curRow = v[0];
            int curCol = v[1];
            int curWeight = v[2];

            for(vector<int> delta: deltaXY){
                int nextRow = curRow+delta[0];
                int nextCol = curCol+delta[1];
                if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && grid[nextRow][nextCol] == 0){
                    int newWeight = curWeight + 1;
                    
                    if(newWeight < distance[nextRow * m + nextCol]){
                        if(nextRow == n-1 && nextCol == m-1){}
                        else q.push({nextRow, nextCol, newWeight});
                        distance[nextRow * m + nextCol] = newWeight;
                    }
                }
            }
        }

        if(distance.back() == INT_MAX) return -1;
        return distance.back();
    }
};