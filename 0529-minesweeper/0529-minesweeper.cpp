/*
        M -> unrevealed mines
        E -> unrevealed empty square
        B -> revealed empty square
        X -> revealed mine

        Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
        Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
           0   1.  2.  3.  4
        0["E","E","E","E","E"]
        1["E","E","M","E","M"]
        2["E","E","E","E","E"]
        3["E","E","E","E","E"]

        ["B","1","E","1","B"]
        ["B","1","M","1","B"]
        ["B","1","1","1","B"]
        ["B","B","B","B","B"]
*/
class Solution {
public:
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    
    bool isValid(vector<vector<char>>& board, int i, int j) {
        return (i >= 0 && j >= 0 && i < board.size() && j < board[0].size());
    }
    
    int hasAdjacentMine(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        for (int k=0; k<8; k++) {
            int I = i + dx[k];
            int J = j + dy[k];
            if (isValid(board, I, J) && board[I][J] == 'M')
                count++;
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if (min(i, j) < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]) return;
        visited[i][j] = true;
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return;
        }
        if (board[i][j] == 'E') {
            int c = hasAdjacentMine(board, i, j);
            if (c == 0) {
                board[i][j] = 'B';
                for (int k=0; k<8; k++) {
                    dfs(board, visited, i+dx[k], j+dy[k]);
                }
            }
            else {
                board[i][j] = c + '0';
                return;
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, visited, click[0], click[1]);
        return board;
    }
};