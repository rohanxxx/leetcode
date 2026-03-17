class Solution {
public:
    bool dfs(int r, int c, int i, string& word, vector<vector<char>>& board, vector<pair<int, int>>& dir){
        int n = board.size();
        int m = board[0].size();
        int k = word.size();

        if(i == k) return true;

        if(r < 0 || r >= n || c < 0 || c >= m || board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '0';

        for(auto it : dir){
            int adjr = r + it.first;
            int adjc = c + it.second;
            if(dfs(adjr, adjc, i + 1, word, board, dir)){
                board[r][c] = temp;
                return true;
            }
        }

        board[r][c] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int n = board.size();
        int m = board[0].size();

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(dfs(r, c, 0, word, board, dir)){
                    return true;
                }
            }
        }

        return false;
    }
};