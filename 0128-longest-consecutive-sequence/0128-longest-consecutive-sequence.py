class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)

        ans = 0
        for num in nums_set:
            count = 1
            if num-1 not in nums_set:
                curr = num
                while curr+1 in nums_set:
                    curr += 1
                    count += 1
                ans = max(count, ans)
        
        return ans
        
        