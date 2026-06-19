class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altSum, maxAlt = 0, 0 
        for i in range(len(gain)):
            altSum += gain[i]
            maxAlt = max(altSum, maxAlt)

        return maxAlt

        