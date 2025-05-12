/*
    return the length of the shortest path that visits every node
    graph: [[1,2,3],[0],[0],[0]]
                0    1.  2.  3

                2 - 0 - 1 
                    |
                    3
    graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
              0.   1.      2.     3.   4
            
            0 - 1 - 2 - 3
                |  /  
                4
    
    output is 4

*/  
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int endingMask = (1 << n) - 1;
        vector<vector<bool>> seen(n, vector<bool>(endingMask + 1, false));
        queue<pair<int, int>> q;

        // Initialize the queue with each node and a mask indicating only that node has been visited
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            q.push({i, mask});
            seen[i][mask] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, mask] = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == endingMask) {
                        return steps + 1;
                    }
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        q.push({neighbor, nextMask});
                    }
                }
            }
            steps++;
        }

        return -1; // Should not reach here
    }
};