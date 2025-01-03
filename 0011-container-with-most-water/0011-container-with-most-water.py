class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        mostWater = 0
        left, right = 0, len(height)-1

        while left < right:
            if height[left] <= height[right]:
                mostWater = max(mostWater, height[left]*(right-left))
                left += 1
                continue
            mostWater = max(mostWater, height[right]*(right-left))
            right -= 1
        
        return mostWater
        