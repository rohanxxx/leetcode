class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # Get the number of rows and columns
        row = len(matrix)
        column = len(matrix[0])
        
        # Transpose the matrix
        for r in range(row):
            for c in range(r, column):
                matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]
        
        # Reverse each row
        for r in range(row):
            matrix[r] = matrix[r][::-1]