class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || j == 0 || i == n-1 || j == m-1){
                        board[i][j] = 'E';
                        q.push({i,j});
                    }
                }
            }
        }

        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(auto offset: dir){
                int adjr = offset.first + r;
                int adjc = offset.second + c;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(board[adjr][adjc] == 'O'){
                        board[adjr][adjc] = 'E';
                        q.push({adjr, adjc});
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};