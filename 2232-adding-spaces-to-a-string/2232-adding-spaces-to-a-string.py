class Solution(object):
    def addSpaces(self, s, spaces):
        """
        :type s: str
        :type spaces: List[int]
        :rtype: str
        """

        size = len(s)
        it = 0
        ans = []

        for i in range(size):
            if it < len(spaces) and i == spaces[it]:
                it += 1
                ans.append(" ")
            ans.append(s[i])

        return "".join(ans)
        