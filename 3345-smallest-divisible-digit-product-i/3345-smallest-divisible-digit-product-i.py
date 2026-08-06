class Solution:
    def get_product(self, n: int) -> int:
        x = n
        product = 1
        while x > 0:
            digit = x%10
            product *= digit
            x //= 10
        return product

    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n, 101):
            product = self.get_product(i)
            if product % t == 0:
                return i
        
        return -1
        