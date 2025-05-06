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

        int endingMask = pow(2, n) - 1;
        vector<vector<bool>> seen(n, vector<bool>(endingMask + 1, false));
        queue<pair<int, int>> q;

        // Initialize the queue with each node and a mask indicating only that node has been visited
        for (int i = 0; i < n; ++i) {
            int mask = pow(2, i);
            //cout << "i: " << i << endl;
            //cout << "mask: " << mask << endl;
            q.push({i, mask});
            seen[i][mask] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, mask] = q.front();
                q.pop();
                //cout << "node: " << node << ", mask: " << mask << endl;
                for (int neighbor : graph[node]) {
                    int nextMask = mask | int(pow(2, neighbor));
                    //cout << "nextMask: " << nextMask << ", neighbor: " << neighbor << endl;
                    if (nextMask == endingMask) {
                        return steps + 1;
                    }
                    if (seen[neighbor][nextMask] == false) {
                        seen[neighbor][nextMask] = true;
                        //cout << "line 53 " << endl;
                        q.push({neighbor, nextMask});
                    }
                }
                cout << endl;
            }
            steps++;
        }

        return -1; // Should not reach here
    }
};