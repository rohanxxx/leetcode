class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1: return True
        pow = 1
        for i in range(1,n+1):
            pow *= 2
            if pow == n: 
                return True
            if pow > n:
                return False
        return False


        