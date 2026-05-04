  /*
    0 1 2 3
  0 0 1 2 3
  1 0 1 2 3
  2 0 1 2 3
  3 0 1 2 3
  */

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        queue<vector<int>> q; q.push(entrance);
        visited[entrance[0]][entrance[1]] = 1;

        int count = 0;
        //TC: O(N*M*4)
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int r = q.front()[0];
                int c = q.front()[1];

                q.pop();

                //c = m-1 || c == 0 || r == n-1 || r == 0
                if(!(r == entrance[0] && c == entrance[1]) && (r == 0 || r == n-1 || c == 0 || c == m-1)){
                    return count;
                }

                //TC: O(4)
                for(auto it: dir){
                    int adjr = it[0]+r;
                    int adjc = it[1]+c;
                    if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m || visited[adjr][adjc] == 1 || maze[adjr][adjc] == '+'){
                        continue;
                    }

                    //other it's legit and we push
                    q.push({adjr, adjc});
                    visited[adjr][adjc] = 1;
                }
            }
            count++;
        }

        return -1;
    }
};