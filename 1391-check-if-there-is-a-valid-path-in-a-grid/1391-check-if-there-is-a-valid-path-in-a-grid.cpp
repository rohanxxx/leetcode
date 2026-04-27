class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        pair<int, int> left = {0,-1}, right = {0,1}, upper = {-1,0}, lower = {1,0};
        
        unordered_map<int, vector<pair<int, int>>> dir;
        //1->left & right
        dir[1].push_back(left);
        dir[1].push_back(right);
        //2-> upper & lower
        dir[2].push_back(upper);
        dir[2].push_back(lower);
        //3->left & lower
        dir[3].push_back(left);
        dir[3].push_back(lower);
        //4->right & lower
        dir[4].push_back(right);
        dir[4].push_back(lower);
        //5->left & upper
        dir[5].push_back(left);
        dir[5].push_back(upper);
        //6->right & upper
        dir[6].push_back(right);
        dir[6].push_back(upper);

        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int,int>> q; 
        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == n-1 && c == m-1){
                return true;
            }

            for(auto it: dir[grid[r][c]]){
                int adjr = r + it.first;
                int adjc = c + it.second;

                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m){
                    continue;
                }

                // ✅ FIXED compatibility checks

                // moving UP → neighbor must open UP
                if(it == upper && !(grid[adjr][adjc] == 2 || grid[adjr][adjc] == 3 || grid[adjr][adjc] == 4)){
                    continue;
                }

                // moving DOWN → neighbor must open DOWN
                if(it == lower && !(grid[adjr][adjc] == 2 || grid[adjr][adjc] == 5 || grid[adjr][adjc] == 6)){
                    continue;
                }

                // moving LEFT → neighbor must open LEFT
                if(it == left && !(grid[adjr][adjc] == 1 || grid[adjr][adjc] == 4 || grid[adjr][adjc] == 6)){
                    continue;
                }

                // moving RIGHT → neighbor must open RIGHT
                if(it == right && !(grid[adjr][adjc] == 1 || grid[adjr][adjc] == 3 || grid[adjr][adjc] == 5)){
                    continue;
                }

                if(visited[adjr][adjc]){
                    continue;
                }

                visited[adjr][adjc] = 1;
                q.push({adjr, adjc});
            }
        }

        return false;
    }
};