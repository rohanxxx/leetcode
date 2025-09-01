import heapq

class Solution(object):
    def calculateGain(self, passes, total):
        # force float division
        curRatio = passes / float(total)
        newRatio = (passes + 1) / float(total + 1)
        return newRatio - curRatio

    def maxAverageRatio(self, classes, extraStudents):
        maxHeap = []
        for passes, total in classes:
            gain = self.calculateGain(passes, total)
            heapq.heappush(maxHeap, (-gain, passes, total))  # max-heap via negative gain

        while extraStudents > 0:
            extraStudents -= 1
            _, passes, total = heapq.heappop(maxHeap)

            passes += 1
            total += 1

            newGain = self.calculateGain(passes, total)
            heapq.heappush(maxHeap, (-newGain, passes, total))

        totalSumRatio = 0.0
        while maxHeap:
            _, passes, total = heapq.heappop(maxHeap)
            totalSumRatio += passes / float(total)

        return totalSumRatio / float(len(classes))