class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> safe(n, vector<int>(m, 0));

        queue<vector<int>> q;

        if(grid[0][0] == 1){
            health -= 1;
            safe[0][0] -= 1;
        }

        if(health > 0){
            q.push({health, 0, 0});
        }

        vector<vector<int>> offset = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()){
            auto it = q.front(); q.pop();

            int curHealth = it[0];
            int r = it[1];
            int c = it[2];

            if(r == n-1 && c == m-1){
                return true;
            }

            for(auto ne: offset){
                int adjr = ne[0] + r;
                int adjc = ne[1] + c;

                if(adjr < 0 || adjc < 0 || adjr >= n || adjc >= m){
                    continue;
                }

                //now that it's valid check the other side
                int newHealth = curHealth;
                if(grid[adjr][adjc] == 1){
                    newHealth -= 1;
                }

                if(newHealth > 0 && safe[adjr][adjc] < newHealth){
                    safe[adjr][adjc] = newHealth;
                    q.push({newHealth, adjr, adjc});
                }
            }
        }

        return false;
    }
};