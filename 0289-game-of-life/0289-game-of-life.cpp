/*
    board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    [0,1,0]
    [0,0,1]
    [1,1,1]
    [0,0,0]

    [0,0,0]
    [1,0,1]
    [0,1,1]
    [0,1,0]

*/
class Solution {

public:
    //SC: O(2*N*M)
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        //TC: O(N*M)
        //SC: O(N*M)
        vector<vector<int>> state(n, vector<int>(m, 0));
        //8 directional search
        //SC: O(2*8)
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1, 0}, {-1, 0}, 
                                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        //TC: O(N*M*8)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int count = 0;
                //TC: O(8)
                for(auto& it: dir){
                    int adjr = it[0]+i;
                    int adjc = it[1]+j;
                    if(adjr >= 0 && adjc >= 0 && adjr < n && adjc < m){
                        count += board[adjr][adjc];
                    }
                }
                //if current cell dead or alive
                //TC: O(1)
                if(board[i][j] == 1){
                    if(count == 2 || count == 3) state[i][j] = 1;
                    if(count < 2) state[i][j] = 0;
                    if(count > 3) state[i][j] = 0;
                }
                else{
                    if(count == 3) state[i][j] = 1;
                }
            }
        }

        board = state;
    }
};