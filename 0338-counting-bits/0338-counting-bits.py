class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        ans = [0]
        for i in range(1, n+1):
            decVal = i
            count = 0
            while decVal > 0:
                count += decVal & 1
                decVal >>= 1
            ans.append(count)
        
        return ans
        