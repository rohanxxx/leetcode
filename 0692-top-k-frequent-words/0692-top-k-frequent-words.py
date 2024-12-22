class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counter = Counter(words)
        heap = [(-freq, word) for word, freq in counter.items()]
        heapify(heap)

        topKFreq = []

        for i in range(k):
            topKFreq.append(heappop(heap)[1])
        
        return topKFreq


        