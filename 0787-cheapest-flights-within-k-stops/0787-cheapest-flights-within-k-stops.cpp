class Solution {
public:
    //TC: O(N+E+N*ELogN)
    //TC: O(N+E)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        //O(E)
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v,w});
        }

        //TC: O(N)
        vector<int> costs(n, INT_MAX);
        //{totalCost, node, stopCount}
        queue<vector<int>> q; q.push({0, src, 0});
        costs[src] = 0;

        //TC: O(N*MAX(E)*LogN)
        while(!q.empty()){
            int curNode = q.front()[1];
            int curCost = q.front()[0];
            int curStop = q.front()[2];
            q.pop();
            
            if(curStop > k) continue;
            //grow bfs
            //TC: O(max(E))
            for(auto adj: graph[curNode]){
                int adjNode = adj.first;
                int adjCost = adj.second;
                int totalCost = adjCost + curCost;
                int totalStop = curStop + 1;
                if(totalCost < costs[adjNode]){
                    costs[adjNode] = totalCost;
                    q.push({totalCost, adjNode, totalStop});
                }
            }
        }
        
        if(costs[dst] == INT_MAX) return -1;
        
        return costs[dst];
    }
};