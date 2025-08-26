class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        ans = 0
        maxDiagonal = float("-inf")
        for dimension in dimensions:
            l, w = dimension[0], dimension[1]
            curArea = l * w
            diagonal = sqrt(w*w + l*l)
            if diagonal >= maxDiagonal:
                if diagonal == maxDiagonal:
                    ans = max(curArea, ans)
                else: 
                    ans = curArea
                maxDiagonal = diagonal

        return ans



        