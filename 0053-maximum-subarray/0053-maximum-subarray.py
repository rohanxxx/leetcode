class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        currentSum, maxSum = 0, float('-inf')
        for n in nums:
            currentSum += n
            maxSum = max(currentSum, maxSum)
            if currentSum < 0:
                currentSum = 0
        return maxSum
        