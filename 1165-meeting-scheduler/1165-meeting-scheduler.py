class Solution(object):
    def minAvailableDuration(self, slots1, slots2, duration):
        """
        :type slots1: List[List[int]]
        :type slots2: List[List[int]]
        :type duration: int
        :rtype: List[int]
        """
        slots1.sort()
        slots2.sort()

        p1, p2 = 0, 0
        s1, s2 = len(slots1), len(slots2)

        while p1 < s1 and p2 < s2:
            leftBound = max(slots1[p1][0], slots2[p2][0])
            rightBound = min(slots1[p1][1], slots2[p2][1])

            if rightBound - leftBound >= duration:
                return [leftBound, leftBound+duration]
            
            if slots1[p1][1] < slots2[p2][1]:
                p1 += 1
            else:
                p2 += 1
        
        return []
        