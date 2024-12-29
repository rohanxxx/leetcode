class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # dictonery
        mp = {0: 1}
        count, prefix = 0, 0

        for num in nums:
            prefix += num
            remainder = prefix % k
            if remainder in mp:
                count += mp[remainder]
            
            # if the remainder doesn't exist then return 0 them increment by 1
            mp[remainder] = mp.get(remainder, 0) + 1
        
        return count

        