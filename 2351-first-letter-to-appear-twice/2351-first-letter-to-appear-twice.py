class Solution:
    def repeatedCharacter(self, s: str) -> str:
        letterMap = [0]*26
        for c in s:
            if letterMap[ord(c)-ord('a')] > 0:
                return c
            letterMap[ord(c)-ord('a')] += 1
        
        return ""