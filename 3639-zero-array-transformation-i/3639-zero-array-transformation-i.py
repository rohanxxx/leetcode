class Solution(object):
    def isZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: bool
        """
        n = len(nums)
        prefix = [0] * (n+1)

        for q in queries:
            left, right = q[0], q[1]
            prefix[left] += 1
            prefix[right+1] -= 1

        for i in range(1, n+1):
            prefix[i] += prefix[i-1]
        for i in range(n):
            # print(prefix[i])
            nums[i] -= prefix[i]
            if(nums[i] > 0):
                return False
        return True
        