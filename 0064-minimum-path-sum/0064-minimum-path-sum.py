class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # m is row size
        m = len(grid)
        # n is col size
        n = len(grid[0])

        # initializing the dp size
        dp = [[0]*n for i in range(m)]

        dp[m-1][n-1] = grid[m-1][n-1]
        for i in range(n-2, -1, -1):
            dp[m-1][i] += dp[m-1][i+1]
        for i in range(m-2, -1, -1):
            dp[i][n-1] += dp[i+1][n-1]

        # goes bottom to up
        for i in range(m-2, -1, -1):
            # goes right to left:
            for j in range(n-2, -1, -1):
                dp[i][j] = min(dp[i][j+1], dp[i+1][j])

        return dp[0][0]
        
        