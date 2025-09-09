/*
    find the shortest path from s to d, but you can hop at most k edges
    in other words make the k weight of at most k edges to 0, then find the shortest path
    between s to d

    return the length of the shortest path from s to d with the given condition

    Input: n = 4, edges = [[0,1,4],[0,2,2],[2,3,6]], s = 1, d = 3, k = 2
    Output: 2
        4
    0 ------ 1
    |
    | 2
    |
    2 ------ 3
        6
*/
class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<vector<pair<int, int>>> graph(n);
        //TC: O(E)
        for(auto& it: edges){
            int u, v, w;
            u = it[0];
            v = it[1];
            w = it[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        //TC: O(N+E)
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        
        //{node, hopCount}
        dist[s][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        //{dist, startNode, parentNode, hopCount}
        minHeap.push({0, s, -1, 0});

        //TC:O(N)
        while(!minHeap.empty()){
            auto top = minHeap.top(); minHeap.pop();
            int curCost = top[0];
            int curNode = top[1];
            int parentNode = top[2];
            int kCount = top[3];

            if(curNode == d) return curCost;

            //now traverse
            //TC:O(E)
            for(auto [adjn, w]: graph[curNode]){
                //if parent then skip
                if(adjn == parentNode) continue;
                if(kCount + 1 <= k){
                    if(curCost < dist[adjn][kCount+1]){
                        dist[adjn][kCount+1] = curCost;
                        minHeap.push({curCost, adjn, curNode, kCount+1});
                    }
                }
                if(curCost+w < dist[adjn][kCount]){
                    dist[adjn][kCount] = curCost + w;
                    minHeap.push({curCost+w, adjn, curNode, kCount});
                }
            }
        }

        return -1;
    }
};