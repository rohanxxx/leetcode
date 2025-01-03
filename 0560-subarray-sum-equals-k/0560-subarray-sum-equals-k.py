class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mp = {0: 1}
        count, prefix = 0, 0

        for num in nums:
            prefix += num
            dif = prefix-k;

            if dif in mp:
                count += mp[dif]
            
            mp[prefix] = mp.get(prefix, 0)+1
        
        return count
        