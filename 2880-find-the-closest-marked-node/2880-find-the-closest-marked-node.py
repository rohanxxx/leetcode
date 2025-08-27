class Solution(object):
    def minimumDistance(self, n, edges, s, marked):
        graph = [[] for i in range(n)]

        for u, v, cost in edges:
            graph[u].append((v, cost))

        heap = [(0, s)]
        dist = [float('inf')] * n
        dist[s] = 0

        marked_set = set(marked)

        while heap:
            curCost, curNode = heapq.heappop(heap)
            if curNode in marked_set:   # fixed
                return curCost

            for v, w in graph[curNode]:
                newCost = curCost + w
                if newCost < dist[v]:
                    dist[v] = newCost
                    heapq.heappush(heap, (newCost, v))

        return -1