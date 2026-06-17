class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        #weights.reverse()
        for word in words:
            word_sum = 0
            for c in word:
                word_sum += weights[ord(c)-ord('a')]
            ans.append(chr(ord('z') - (word_sum % 26)))
        return "".join(ans)
