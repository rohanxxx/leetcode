class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        group = [0] * n
        
        count = 0
        for i in range(1, n):
            if nums[i]-nums[i-1] > maxDiff:
                count += 1
            group[i] = count
        
        ans: list[bool] = []

        for q in queries:
            u, v = q[0], q[1]
            ans.append(group[u] == group[v])
        
        return ans



        