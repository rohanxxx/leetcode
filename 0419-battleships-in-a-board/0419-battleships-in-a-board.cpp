/*
    Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
    Output: 2

    // battleships can be only vertical and horizontal?
    
    [".","X",".","X"]
    ["X","X","X","X"]
    [".","X",".","X"]

    dfs(int r, int c, string command, board)
    for(i->n){
        for(j -> m){
            if(board[i][j] == 'X'){
                isLandCount++;
                board[i][j] = '.';
                dfs(i,j, '*', board)
            }
        }
    }
*/
class Solution {
public:
    void dfs(int r, int c, string dir, vector<vector<char>>& board){
        //here we will dfs through it's direction
        int n = board.size();
        int m = board[0].size();

        if(dir == "*"){
            //check right first
            if(c + 1 < m && board[r][c+1] == 'X'){
                board[r][c+1] = '.';
                dfs(r, c+1, "right", board);
            }
            else if(r+1 < n && board[r+1][c] == 'X'){
                board[r+1][c] = '.';
                dfs(r+1, c, "down", board);
            }
        }
        else if(dir == "right"){
            //keep checking right
            if(c + 1 < m && board[r][c+1] == 'X'){
                board[r][c+1] = '.';
                dfs(r, c+1, "right", board);
            }
        }
        else if(dir == "down"){
            //keep checking down
            if(r+1 < n && board[r+1][c] == 'X'){
                board[r+1][c] = '.';
                dfs(r+1, c, "down", board);
            }
        }

        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();       //row size
        int m = board[0].size();    //col Size
        int islandCount = 0;        //keeps track of the islandCount
        //TC: O(N*M + 2E)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X'){
                    islandCount++;
                    board[i][j] = '.';
                    dfs(i,j, "*", board);
                }
            }
        }

        return islandCount;
    }
};