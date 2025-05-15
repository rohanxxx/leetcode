/*
    sample output = 3
    Input: grid = [
        ["X","X","X","X","X","X"],
        ["X","*","O","O","O","X"],
        ["X","O","O","#","O","X"],
        ["X","X","X","X","X","X"]
        ]
*/
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();    //row size
        int m = grid[0].size(); //col size

        int startRow = INT_MIN;
        int startCol = INT_MIN;

        //dist vector hold the shortest path length
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        //minHeap
        //{curDis, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        //first get start row and col along with the food cells
        //TC: O(N*M)
        //SC: O(N*M)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    startRow = i;
                    startCol = j;
                    dist[i][j] = 0;
                    pq.push({0,i,j});
                    break;
                }
            }
        }

        //edge case check
        if(startRow == INT_MIN || startCol == INT_MIN){
            return -1;
        }
        if(pq.empty()){
            return -1;
        }

        //this gives you possible moves from each cell point
        vector<vector<int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        //TC: O(N*M*log(NM)+4E)
        while(!pq.empty()){
            int curDis = pq.top()[0];
            int curRow = pq.top()[1];
            int curCol = pq.top()[2];
            
            pq.pop();

            if(grid[curRow][curCol] == '#'){
                return curDis;
            }
            //here we make our 4 directional BFS search
            //TC: O(4E)
            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                //boundary check
                if(adjr >= 0 && adjc >= 0 && adjr < n && adjc < m){
                    //check adjr && adjc is empty or the starting cell?
                    if(grid[adjr][adjc] == 'O' || grid[adjr][adjc] == '#'){
                        if(curDis + 1 < dist[adjr][adjc]){
                            dist[adjr][adjc] = curDis+1;
                            pq.push({curDis+1, adjr, adjc});
                        }
                    }
                }
            }
        }

        return -1;
    }
};