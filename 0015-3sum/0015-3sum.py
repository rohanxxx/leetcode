class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        triplet_set = set()

        for i in range(len(nums)):
            j, k = i+1, len(nums)-1
            while j < k:
                sum = nums[i]+nums[j]+nums[k]
                if sum == 0:
                    triplet_set.add((nums[i], nums[j], nums[k]))
                    j += 1
                else:
                    if sum < 0:
                        j += 1
                    else:
                        k -= 1
        
        ans = [list(triplet) for triplet in triplet_set]

        return ans
        