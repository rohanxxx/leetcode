class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = []
        row, column = len(matrix), len(matrix[0])
        left, right = 0, column-1
        up, down = 0, row-1

        while len(result) < row * column:
            for c in range(left, right+1):
                result.append(matrix[up][c])
            for r in range(up+1, down+1):
                result.append(matrix[r][right])
            
            if up != down:
                for c in range(right-1, left-1, -1):
                    result.append(matrix[down][c])
            if left != right:
                for r in range(down-1, up, -1):
                    result.append(matrix[r][left])
            
            up += 1
            down -= 1
            left += 1
            right -= 1
        
        return result
        
        