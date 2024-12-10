class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        count = [0] * 3
        n = len(s)

        # counts the occurences
        for c in s:
            count[ord(c)-ord("a")] += 1
        
        # check if we have enough characters
        for i in range(3):
            if(count[i] < k):
                return -1

        window = [0]*3
        left, maxWindow = 0, 0

        for right in range(n):
            window[ord(s[right]) - ord("a")] += 1

            while left <= right and (
                count[0] - window[0] < k or 
                count[1] - window[1] < k or
                count[2] - window[2] < k
            ):
                window[ord(s[left]) - ord("a")] -= 1
                left += 1

            maxWindow = max(maxWindow, right-left+1)

        return n-maxWindow
        