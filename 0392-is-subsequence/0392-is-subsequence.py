class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i, size = 0, len(s)
        for c in t:
            if i < size and c == s[i]:
                i += 1
        
        if i < size:
            return False
        return True
        