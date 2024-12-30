class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        # put all the words into words list
        words = s.split()
        # now reverse the list of words
        reverseWords = words[::-1]

        # add spaces in between words
        return " ".join(reverseWords)
        