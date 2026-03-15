class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;

        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int, int>> q;

        // Pacific: top row + left col
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(r == 0 || c == 0){
                    if(dp[r][c] == 0){
                        dp[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto it: dir){
                int adjr = r + it.first;
                int adjc = c + it.second;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(heights[r][c] <= heights[adjr][adjc] && dp[adjr][adjc] < 1){
                        q.push({adjr, adjc});
                        dp[adjr][adjc] = 1;
                    }
                }
            }
        }

        // Atlantic: bottom row + right col
        for(int r = n-1; r >= 0; r--){
            for(int c = m-1; c >= 0; c--){
                if(r == n-1 || c == m-1){
                    if(dp[r][c] < 2){
                        dp[r][c] += 2;
                        q.push({r,c});
                    }
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(dp[r][c] == 3){
                ans.push_back({r,c});
            }

            for(auto it: dir){
                int adjr = r + it.first;
                int adjc = c + it.second;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(heights[r][c] <= heights[adjr][adjc] && dp[adjr][adjc] < 2){
                        q.push({adjr, adjc});
                        dp[adjr][adjc] += 2;
                    }
                }
            }
        }

        return ans;
    }
};