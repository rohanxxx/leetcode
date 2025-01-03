class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        nums.sort()
        count, maxCount, prev = 1, 1, nums[0]

        for i in range(1, len(nums)):
            dif = nums[i] - prev
            if dif == 1:
                count += 1
                maxCount = max(count, maxCount)
            else:
                if dif > 1:
                    count = 1
            prev = nums[i]
        
        return maxCount
