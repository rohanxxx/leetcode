class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        maxRow = maxCol = float("-inf")
        minRow = minCol = float("inf")

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    maxRow = max(maxRow, i)
                    minRow = min(minRow, i)
                    maxCol = max(maxCol, j)
                    minCol = min(minCol, j)
        
        return (int)((maxRow - minRow + 1) * (maxCol - minCol + 1))
        