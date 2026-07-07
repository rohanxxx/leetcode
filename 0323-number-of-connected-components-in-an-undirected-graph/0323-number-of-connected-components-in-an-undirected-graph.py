class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = []
        for i in range(n):
            graph.append([])

        for edge in edges:
            u = edge[0]
            v = edge[1]
            graph[u].append(v)
            graph[v].append(u)
            
        visited = [0] * n
        
        componentCount = 0
        for i in range(n):
            if visited[i] == 0:
                componentCount += 1

                dq = deque()
                dq.append(i)
                visited[i] = 1

                while len(dq):
                    node = dq.popleft()
                    #now traverse
                    for adjNode in graph[node]:
                        if visited[adjNode] == 0:
                            dq.append(adjNode)
                            visited[adjNode] = 1
        
        return componentCount
                    


