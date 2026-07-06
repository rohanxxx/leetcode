class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq = {}
        for i in range(len(s)):
            freq[s[i]] = freq.get(s[i], 0) + 1
        
        for i in range(len(t)):
            if t[i] in freq and freq[t[i]] > 0:
                freq[t[i]] -= 1
            else:
                return False
        
        return True
        