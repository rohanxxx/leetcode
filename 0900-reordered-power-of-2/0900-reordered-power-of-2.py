class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """

        s = sorted(str(n))
        for i in range(30):
            powOfTwos = sorted(str(1 << i))
            if powOfTwos == s:
                return True
        
        return False
            
        
        