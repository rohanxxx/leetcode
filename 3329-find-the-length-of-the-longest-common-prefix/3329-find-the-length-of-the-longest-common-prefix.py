class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        prefixes = set()
        
        for val in arr1:
            while val not in prefixes and val > 0:
                prefixes.add(val)
                val /= 10
        
        longestPrefixCount = 0

        for val in arr2:
            while val not in prefixes and val > 0:
                val /= 10
            if val > 0:
                string = str(val)
                longestPrefixCount = max(longestPrefixCount, len(string))
        

        return longestPrefixCount
        