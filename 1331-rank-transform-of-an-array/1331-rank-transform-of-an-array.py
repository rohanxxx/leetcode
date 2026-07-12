class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        dic = defaultdict(list)
        for i in range(len(arr)):
            dic[arr[i]].append(i)
        
        dic = dict(sorted(dic.items()))

        rank = 1
        ans = [0] * len(arr)
        for element, indices in dic.items():
            for index in indices:
                ans[index] = rank
            rank += 1
        return ans
        