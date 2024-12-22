class Solution(object):
    def __init__(self):
        self.travelNeeded = set()
    
    def solve(self, dp, costs, lastDay, currDay):
        if currDay > lastDay:
            return 0
        if currDay not in self.travelNeeded:
            return self.solve(dp, costs, lastDay, currDay+1)
        if dp[currDay] != -1:
            return dp[currDay]
        
        oneDay = costs[0] + self.solve(dp, costs, lastDay, currDay+1)
        sevenDay = costs[1] + self.solve(dp, costs, lastDay, currDay+7)
        thirtyDay = costs[2] + self.solve(dp, costs, lastDay, currDay+30)

        dp[currDay] = min(oneDay, min(sevenDay, thirtyDay))
        return dp[currDay]
    
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        lastDay = days[-1]
        dp = [-1]* (lastDay+1)
        for i in days:
            self.travelNeeded.add(i)
        return self.solve(dp, costs, lastDay, 1)
        