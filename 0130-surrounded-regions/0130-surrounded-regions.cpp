class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        //TC -> O(n*m)
        //mark the edge islands with 'E'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                    }
                }
            }
        }

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int curRow = p.first;
            int curCol = p.second;
            
            board[curRow][curCol] = 'E';
            
            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(board[adjr][adjc] == 'O'){
                        q.push({adjr, adjc});
                    }
                }
            }
        }

        //TC -> O(n*m)
        //convert the regions to the water land
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        //TC -> O(n*m)
        //mark the edge islands back to '0'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};