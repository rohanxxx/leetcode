class Solution {
public:
    int size;
    vector<vector<string>> solutions;

    vector<string> createBoard(vector<vector<char>> state){
        vector<string> board;
        for(int row = 0; row < size; row++){
            string current_row(state[row].begin(), state[row].end());
            board.push_back(current_row);
        }
        return board;
    }

    void backtrack(int row, unordered_set<int> diagonals, unordered_set<int> antiDiagonals, unordered_set<int> cols, vector<vector<char>> state){
        if(row == size){
            solutions.push_back(createBoard(state));
            return;
        }

        for(int col = 0; col < size; col++){
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;

            if(cols.count(col)||diagonals.count(currDiagonal)||antiDiagonals.count(currAntiDiagonal)) continue;

            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            state[row][col] = 'Q';

            backtrack(row+1, diagonals, antiDiagonals, cols, state);

            cols.erase(col);
            diagonals.erase(currDiagonal);
            antiDiagonals.erase(currAntiDiagonal);
            state[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<vector<char>> emptyBoard(size, vector<char>(size, '.'));
        backtrack(0, unordered_set<int>(), unordered_set<int>(), unordered_set<int>(), emptyBoard);
        return solutions;
    }
};