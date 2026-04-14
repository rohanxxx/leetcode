class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<long long> next(n+1, 0), curr(n+1, 0);

        // base case: dp[i][m]
        for(int i = 0; i < n; i++){
            next[i] = 1e15;
        }
        next[n] = 0;

        // iterate over factories
        for(int j = m-1; j >= 0; j--){

            for(int i = n; i >= 0; i--){

                long long res = next[i]; // skip factory

                long long dist = 0;

                for(int k = 0; k < factory[j][1] && i + k < n; k++){
                    dist += abs((long long)robot[i + k] - factory[j][0]);
                    res = min(res, dist + next[i + k + 1]);
                }

                curr[i] = res;
            }

            next = curr;
        }

        return next[0];
    }
};