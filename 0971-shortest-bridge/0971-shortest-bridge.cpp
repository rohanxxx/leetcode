/*
    grid = 
    [0,1,0]
    [0,0,0]
    [0,0,1]

    Input: grid = [
        [1,1,1,1,1]
        [1,0,0,0,1]
        [1,0,1,0,1]
        [1,0,0,0,1]
        [1,1,1,1,1]
    ]

    [0,1]
    [1,0]

    basically first bfs traversal identify's 1st island and at the same keep tracks of the node that's have adjacent of 0 by putting it 
    inside another new queue that stores the border of the island
    also it marks the first visited island in a visited vector

    then we do bfs and seeks the unvisited second island
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();        //row size
        int m = grid[0].size();     //col size

        int isBroken = false;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        //basically first bfs traversal identify's 1st island and at the same keep tracks of the node that's have adjacent of 0 by putting it 
        //inside another new queue that stores the border of the island
        //also it marks the first visited island in a visited vector
        //pair<row, col>
        queue<pair<int, int>> q1, q2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    visited[i][j] = 1;
                    q1.push({i,j});
                    isBroken = true;
                    break;
                }
            }
            if(isBroken == true){
                break;
            }
        }

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        //bfs traversal at the same retrieve the border 0
        //O(N + 4E)
        while(!q1.empty()){
            int curRow = q1.front().first;
            int curCol = q1.front().second;
            q1.pop();
            //4 directional search
            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                //boundary check first
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(visited[adjr][adjc] == 0){
                        visited[adjr][adjc] = 1; //marks as visited
                        if(grid[adjr][adjc] == 1){
                            q1.push({adjr, adjc});
                        }
                        else{
                            q2.push({adjr, adjc});
                        }
                    }
                }
            }
        }

        int steps = 0;
        //then we do bfs and seeks the unvisited second island
        //O(N+4E)
        while(!q2.empty()){
            int qSize = q2.size();
            for(int i = 0; i < qSize; i++){
                //cout << "line 74" << endl;
                int curRow = q2.front().first;
                int curCol = q2.front().second;
                //cout << "curRow: " << curRow << " curCol: " << curCol << endl;
                q2.pop();
                //lowest step count
                if(grid[curRow][curCol] == 1){
                    //cout << "line 79" << endl;
                    return steps;
                }
                //4 directional search
                for(auto it: dir){
                    int adjr = curRow + it[0];
                    int adjc = curCol + it[1];
                    //boundary check first
                    if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                        if(visited[adjr][adjc] == 0){
                            visited[adjr][adjc] = 1; //marks as visited
                            q2.push({adjr, adjc});
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};