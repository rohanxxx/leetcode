/*
    Input: grid = [" /","/ "]
    Output: 2
   
    " /"
    "/ "

    001
    010
    100

    0 1
    1 0

     0 1 2 3 4 5
   0 0 0 0 0 0 1
   1 0 0 0 0 1 0
   2 0 0 0 1 0 0
   3 0 0 1 0 0 0
   4 0 1 0 0 0 0
   5 1 0 0 0 0 0

   forward slash scalled scaled row = row*3 col = col*3+2 dfs(row-1, col-1)
   backward slash scalled row = row*3 scalled col = col*3 dfs(row-1, col+1)

    "/"
    " "

    "/\\",
   "\\/"
   001100
   010010
   001100

*/
class Solution {
public:
    void dfs(int i, int j, int dir, vector<vector<int>>& scalled_grid){
        // i, j = starting scaled coords (the "top" cell of the 3-cell diagonal)
        if(dir == 0){
            // "/" — diagonal runs top-right to bottom-left: col decreases as row increases
            for(int r = i, c = j; r < i + 3; r++, c--){
                scalled_grid[r][c] = 1;
            }
        }
        else{
            // "\" — diagonal runs top-left to bottom-right: col increases as row increases
            for(int r = i, c = j; r < i + 3; r++, c++){
                scalled_grid[r][c] = 1;
            }
        }
    }

    void bfs(int i, int j, vector<vector<int>>& scalled_grid){
        int n = scalled_grid.size();

        queue<pair<int, int>> q;
        q.push({i,j});

        scalled_grid[i][j] = 1;

        vector<vector<int>> dir = {{0,1}, {1,0}, {-1, 0}, {0, -1}};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(auto adj: dir){
                int adjr = r + adj[0];
                int adjc = c + adj[1];

                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= n || scalled_grid[adjr][adjc] == 1){
                    continue;
                }

                q.push({adjr, adjc});
                scalled_grid[adjr][adjc] = 1;
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int scalled_n = 3 * n;
        vector<vector<int>> scalled_grid(scalled_n, vector<int>(scalled_n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    int r = i*3;
                    int c = j*3+2;
                    dfs(r, c, 0, scalled_grid);
                }
                else if(grid[i][j] == '\\'){
                    int r = i*3;
                    int c = j*3;
                    dfs(r, c, 1, scalled_grid);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < scalled_n; i++){
            for(int j = 0; j < scalled_n; j++){
                if(scalled_grid[i][j] == 0){
                    bfs(i, j, scalled_grid);
                    count++;
                }
            }
        }

        return count;
    }
};