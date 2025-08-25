class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        n, m = len(mat), len(mat[0])

        ans = []

        # i = row, j = col, d = direction
        i, j, d = 0, 0, 0

        while i < n and j < m:
            ans.append(mat[i][j])
            if i == n-1 and j == m-1:
                break
            if d == 0:
                if j == m-1:
                    i += 1 
                    d = 1
                elif  i == 0:
                    j += 1
                    d = 1
                else:
                    i -= 1
                    j += 1
            else:
                if i == n-1:
                    j += 1
                    d = 0
                elif j == 0:
                    i += 1
                    d = 0
                else:
                    i += 1
                    j -= 1

        return ans