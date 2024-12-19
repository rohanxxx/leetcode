class Solution(object):
    def vanishIsland(self, grid, row, col):
        if grid[row][col] == '1':
            grid[row][col] = '0'
            
            # Checking up
            if row - 1 >= 0:
                self.vanishIsland(grid, row - 1, col)
            # Checking down
            if row + 1 < len(grid):
                self.vanishIsland(grid, row + 1, col)
            # Checking left
            if col - 1 >= 0:
                self.vanishIsland(grid, row, col - 1)
            # Checking right
            if col + 1 < len(grid[0]):
                self.vanishIsland(grid, row, col + 1)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.vanishIsland(grid, i, j)
                    count += 1
        return count
        