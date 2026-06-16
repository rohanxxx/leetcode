class Solution:
    def processStr(self, s: str) -> str:
        result = []
        for c in s:
            if 'a' <= c <= 'z':
                result.append(c)
            if c == '*':
                if len(result) > 0:
                    result.pop()
            if c == '#':
                result = result + result
            if c == '%':
                result = list(reversed(result))
        
        #joining the characters back to string
        return "".join(result)
        