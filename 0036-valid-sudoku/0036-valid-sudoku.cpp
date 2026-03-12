class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, unordered_set<char>> rowMap, colMap, boxMap;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c > '0'){
                    //if found 
                    if(rowMap[i].find(c) != rowMap[i].end()) return false;
                    if(colMap[j].find(c) != colMap[j].end()) return false;
                    
                    int index = (i/3)*3+(j/3);
                    if(boxMap[index].find(c) != boxMap[index].end()) return false;
                    
                    rowMap[i].insert(c);
                    colMap[j].insert(c);
                    boxMap[index].insert(c);
                }
            }
        }
        return true;
    }
};