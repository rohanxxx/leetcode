class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        hashmap = {}

        left, ans = 0, 0 
        for right in range(len(nums)):
            if nums[right] in hashmap:
                hashmap[nums[right]] += 1
            else:
                hashmap[nums[right]] = 1

            while hashmap[nums[right]] > k:
                hashmap[nums[left]] -= 1
                left += 1
            
            ans = max(ans, right-left+1)
        
        return ans