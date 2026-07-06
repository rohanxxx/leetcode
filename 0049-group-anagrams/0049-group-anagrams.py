class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for i in range(len(strs)):
            word = strs[i]
            mp = [0]*26
            for c in word:
                mp[ord(c)-ord('a')] += 1
            
            key = ""
            for j in range(26):
                for k in range(mp[j]):
                    key += chr(ord('a') + j)
            
            dic.setdefault(key, []).append(word)
        
        ans = []
        
        for key, items in dic.items():
            ans.append(items)
        
        return ans
        
        