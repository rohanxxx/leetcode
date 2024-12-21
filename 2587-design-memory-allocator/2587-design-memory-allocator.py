class Allocator(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.memory = [0]*n
        

    def allocate(self, size, mID):
        """
        :type size: int
        :type mID: int
        :rtype: int
        """
        count, free = 0, 0
        
        for i in range(len(self.memory)):
            if self.memory[i] == 0:
                count += 1
            else:
                count = 0

            if count == size:
                while count:
                    self.memory[i-count+1] = mID
                    count -= 1
                return i-size+1
        return -1
        

    def freeMemory(self, mID):
        """
        :type mID: int
        :rtype: int
        """
        count = 0
        for i in range(len(self.memory)):
            if self.memory[i] == mID:
                self.memory[i] = 0
                count += 1
        return count
        


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)