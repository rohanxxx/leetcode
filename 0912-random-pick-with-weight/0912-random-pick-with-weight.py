class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.prefixSum = []
        for n in w:
            if not self.prefixSum:
                self.prefixSum.append(n)
                continue
            self.prefixSum.append(n+self.prefixSum[-1])

    def pickIndex(self):
        """
        :rtype: int
        """
        # random floar between 0 and 9
        randomNum = random.random()
        targetNum = randomNum * self.prefixSum[-1]
        for i in range(len(self.prefixSum)):
            if targetNum < self.prefixSum[i]:
                return i
        
        return len(self.prefxSum)-1
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()