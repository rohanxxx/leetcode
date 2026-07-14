class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n, ans = len(nums), 0

        for i in range(n):
            count = 0
            for j in range(i, n):
                if nums[j] == target:
                    count += 1
                else:
                    count -= 1
                if count > 0:
                    ans += 1
        
        return ans

        