class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        maxDigit = None
        n = len(num)

        for i in range(n-2):
            if num[i] == num[i+1] and num[i] == num[i+2]:
                if maxDigit == None or maxDigit < ord(num[i])-ord('0'):
                    maxDigit = ord(num[i])-ord('0')

        ans = ""
        if maxDigit is not None:
            for i in range(3):
                ans += str(maxDigit)

        return ans
