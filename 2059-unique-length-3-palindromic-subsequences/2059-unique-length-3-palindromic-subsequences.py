class Solution(object):
    #TC: O(N+26(N+N))
    #SC: O(26)
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, ans = len(s), 0

        #TC: O(N)
        letters = set(s)

        #TC: O(26 * (N+N))
        for letter in letters:
            i, j = -1, 0

            for k in range(n):
                if s[k] == letter:
                    if i == -1:
                        i = k
                    j = k
            inBetween = set()
            for k in range(i+1, j):
                inBetween.add(s[k])
            
            ans += len(inBetween)
        
        return ans



        