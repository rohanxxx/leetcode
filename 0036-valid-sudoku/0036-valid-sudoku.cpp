class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int LEN = 9;
        vector<unordered_set<char>> rows(9), columns(9), boxes(9);

        for(int r = 0; r < LEN; r++){
            for(int c = 0; c < LEN; c++){
                char val = board[r][c];

                if(val == '.') continue;
                
                if(rows[r].find(val) != rows[r].end()) return false;
                if(columns[c].find(val) != columns[c].end()) return false;
                int boxIndex = r/3 *3 + c/3;
                if(boxes[boxIndex].find(val) != boxes[boxIndex].end()) return false;
                
                rows[r].insert(val);
                columns[c].insert(val);
                boxes[boxIndex].insert(val); 
            }
        }
        return true;
    }
};