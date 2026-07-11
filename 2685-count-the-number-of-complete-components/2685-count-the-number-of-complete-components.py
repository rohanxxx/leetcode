class Solution:
    def bfs(self, node: int, visited: List[int], graph: List[List[int]]) -> int:
        q = deque()
        q.append(node)

        visited[node] = 1

        nodeCount = edgeCount = 0
        while len(q) > 0:
            node = q.popleft()
            nodeCount += 1

            for adjNode in graph[node]:
                edgeCount += 1
                if visited[adjNode] == 1:
                    continue
                q.append(adjNode)
                visited[adjNode] = 1
        
        return int((edgeCount/2) == (nodeCount*(nodeCount-1)/2))

    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        #step 1 -> create the graph
        graph = []
        for i in range(n):
            graph.append([])
        
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        #step 2 -> do the bfs
        count = 0
        visited = [0] * n
        for node in range(n):
            if visited[node] == 0:
                count += self.bfs(node, visited, graph)
        
        return count