class Solution {
public:
    unordered_set<int> travelNeeded;
    int solve(vector<int>& dp, vector<int>& costs, int& lastDay, int currDay){
        if(currDay > lastDay) return 0;
        if(travelNeeded.find(currDay) == travelNeeded.end()) return solve(dp, costs, lastDay, currDay+1);
        if(dp[currDay] != -1) return dp[currDay];
        
        int oneDay = costs[0] + solve(dp, costs, lastDay, currDay+1);
        int sevenDay = costs[1] + solve(dp, costs, lastDay, currDay+7);
        int thirtyDay = costs[2] + solve(dp, costs, lastDay, currDay+30);

        dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
        
        return dp[currDay];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay+1,-1);
        for(auto day: days){
            travelNeeded.insert(day);
        }
        return solve(dp, costs, lastDay, 1);
    }
};