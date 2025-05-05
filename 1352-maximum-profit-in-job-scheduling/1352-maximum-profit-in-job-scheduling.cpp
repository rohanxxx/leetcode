class Solution {
public:
    int func(int i, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int>& dp){
        int n = startTime.size();
        if(i == n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int nextIndex = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
        int take = profit[i]+func(nextIndex, startTime, endTime, profit, dp);
        int notTake = func(i+1, startTime, endTime, profit, dp);
        return dp[i] = max(take, notTake);
    } 
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(int i = 0; i < n; i++){
            startTime[i] = jobs[i][0];
            endTime[i] = jobs[i][1];
            profit[i] = jobs[i][2];
        }
        return func(0, startTime, endTime, profit, dp);
    }
};