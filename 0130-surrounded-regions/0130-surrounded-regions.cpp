class Solution {
public:
    int ROW, COL;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j] != 'O') return;
        
        board[i][j] = 'E';
        if (j < COL - 1) dfs(board, i, j + 1);
        if (i < ROW - 1) dfs(board, i + 1, j);
        if (j > 0) dfs(board, i, j - 1);
        if (i > 0) dfs(board, i - 1, j);
    }
    void solve(vector<vector<char>>& board) {
        ROW = board.size();
        COL = board[0].size();
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
                    dfs(board, i, j);
            }
        }
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                    continue;
                }
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};