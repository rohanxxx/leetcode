class Solution {
public:
    /*long long dfs(int i, int j, vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>>& dp){
        int n = robot.size();
        int m = factory.size();

        if(i == n) return 0;
        if(j == m) return 1e15; // FIX: large value instead of INT_MAX

        if(dp[i][j] != -1) return dp[i][j];

        long long res = 1e15;

        // Option 1: skip this factory
        res = dfs(i, j+1, robot, factory, dp);

        // Option 2: assign k robots to this factory
        long long dist = 0;
        for(int k = 0; k < factory[j][1] && i + k < n; k++){
            dist += abs((long long)robot[i + k] - factory[j][0]);
            res = min(res, dist + dfs(i + k + 1, j + 1, robot, factory, dp));
        }

        return dp[i][j] = res;
    }*/

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        //return dfs(0, 0, robot, factory, dp);*/

        for(int i = 0; i <= n; i++){
            if(i == n) continue;
            dp[i][m] = 1e15;
        }

        for(int i = n; i >= 0; i--){
            if(i == n) continue;
            for(int j = m; j >= 0; j--){
                if(j == m) continue;
                long long res = 1e15;

                // Option 1: skip this factory
                res = dp[i][j+1];

                // Option 2: assign k robots to this factory
                long long dist = 0;
                for(int k = 0; k < factory[j][1] && i + k < n; k++){
                    dist += abs((long long)robot[i + k] - factory[j][0]);
                    res = min(res, dist + dp[i + k + 1][j + 1]);
                }

                dp[i][j] = res;
            }
        }

        return dp[0][0];
    }
};