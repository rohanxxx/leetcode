class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}
        maxCount, majorityElement = 0, 0

        for num in nums:
            mp[num] = mp.get(num, 0)+1
            if maxCount < mp[num]:
                maxCount = mp[num]
                majorityElement = num

        if mp[majorityElement] > len(nums)/2:
            return majorityElement
        return -1

        
        