class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        s = "123456789"
        ans: List[int] = []
        for window in range(2, 10):
            left, right = 0, window-1
            while right < 9:
                val = int(s[left:right+1])
                #left, right = left + 1, right + 1
                left, right = left + 1, right + 1
                if val < low or val > high:
                    continue
                
                ans.append(val)

        return ans
        