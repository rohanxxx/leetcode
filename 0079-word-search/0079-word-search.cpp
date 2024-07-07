class Solution {
public:
    int ROWS, COLS;
    vector<vector<char>> boardCopy;

    bool backtrack(int row, int col, const string& word, int index){
        if(index >= word.length()) return true;
        if(row < 0 || row == ROWS || col < 0 || col == COLS || boardCopy[row][col] != word[index]) return false;
        
        boardCopy[row][col] = '#';

        int rowOffset[4] = {0,1,0,-1};
        int colOffset[4] = {1,0,-1,0};

        bool res = false;
        for(int i = 0; i < 4; i++){
            res = backtrack(row+rowOffset[i], col+colOffset[i], word, index+1);
            if (res) break;
        }
        boardCopy[row][col] = word[index];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        boardCopy = board;
        ROWS = board.size(), COLS = board[0].size();

        for(int row = 0; row < ROWS; row++){
            for(int col = 0; col < COLS; col++){
                if(backtrack(row, col, word, 0)) return true;
            }
        }

        return false;
    }
};