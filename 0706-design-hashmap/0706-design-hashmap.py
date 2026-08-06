class MyHashMap:

    def __init__(self):
        self.hashmap = []        

    def put(self, key: int, value: int) -> None:
        if key >= len(self.hashmap):
            self.hashmap.extend([-1]*(key+1-len(self.hashmap)))
        self.hashmap[key] = value

    def get(self, key: int) -> int:
        if key < len(self.hashmap):
            return self.hashmap[key]
        return -1
    def remove(self, key: int) -> None:
        if key < len(self.hashmap):
            self.hashmap[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)