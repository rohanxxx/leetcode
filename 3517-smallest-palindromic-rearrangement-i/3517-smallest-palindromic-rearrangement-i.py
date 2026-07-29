class Solution:
    def smallestPalindrome(self, s: str) -> str:
        bucket = [0]*26
        s = list(s)
        for i in range(int(len(s)/2)):
            bucket[ord(s[i])-ord('a')] += 1
        

        left, right = 0, len(s)-1
        for i in range(26):
            while bucket[i] > 0:
                c = chr(i + ord('a'))

                s[left] = c
                s[right] = c

                left += 1
                right -= 1
                
                bucket[i] -= 1

        return "".join(s)
