class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = {}
        for num in nums:
            dic[num] = dic.get(num, 0)+1
        
        bucket = []
        for i in range(len(nums)+1):
            bucket.append([])
        
        for num, freq in dic.items():
            bucket[freq].append(num)
        
        ans = []
        for i in range(len(bucket)-1, -1, -1):
            for num in bucket[i]:
                if k == 0:
                    return ans
                ans.append(num)
                k -= 1
        
        return ans
