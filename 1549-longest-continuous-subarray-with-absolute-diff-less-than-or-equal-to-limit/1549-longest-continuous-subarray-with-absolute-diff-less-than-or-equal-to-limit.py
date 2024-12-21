class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
         # SortedDict to maintain the elements within the current window
        window = SortedDict()
        left = 0
        max_length = 0

        for right in range(len(nums)):
            if nums[right] in window:
                window[nums[right]] += 1
            else:
                window[nums[right]] = 1

            # Check if the absolute difference between the maximum and minimum values in the current window exceed the limit
            while window.peekitem(-1)[0] - window.peekitem(0)[0] > limit:
                # Remove the element at the left pointer from the SortedDict
                window[nums[left]] -= 1
                if window[nums[left]] == 0:
                    window.pop(nums[left])
                # Move the left pointer to the right to exclude the element causing the violation
                left += 1

            # Update maxLength with the length of the current valid window
            max_length = max(max_length, right - left + 1)

        return max_length

        