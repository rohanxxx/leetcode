/*
Input: board = 
[
    ["X","X","X","X"],
    ["X","O","O","X"],
    ["X","X","O","X"],
    ["X","O","X","X"]
]

Output: 
[
    ["X","X","X","X"],
    ["X","X","X","X"],
    ["X","X","X","X"],
    ["X","O","X","X"]
]
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<vector<int>> q;
        //O(N*M)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == n-1 || j == m-1)){
                    q.push({i,j});
                    board[i][j] = 'E';
                }
            }
        }

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        //now mark region that connects to the edges "E"

        //TC: O(4*N*M)
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int r = it[0];
            int c = it[1];

            //TC: O(4)
            for(auto d: dir){
                int adjr = d[0] + r;
                int adjc = d[1] + c;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(board[adjr][adjc] == 'O'){
                        q.push({adjr, adjc});
                        board[adjr][adjc] = 'E';
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