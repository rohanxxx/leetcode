class Solution {
public:
    /*
        Input: n = 4, edges = [[0,1,1],[1,2,3],[2,3,2],[0,3,4]], s = 0, marked = [2,3]
        Output: 4

          1.   3.   2.    4
        0 -> 1 -> 2 -> 3 <--
         \_________________|
    */
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        //first create the graph
        //TC: O(E)
        vector<vector<pair<int, int>>> graph(n);
        for(auto& it: edges){
            int u = it[0], v = it[1], cost = it[2];
            graph[u].push_back({v, cost});
        }
        //use minQ to find the closest marked node from s
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        //{cost, node}
        minHeap.push({0, s});
        //TC: O(N)
        vector<int> minCost(n, INT_MAX); minCost[s] = 0;
        //TC: O(N)
        unordered_set<int> markedNodes(marked.begin(), marked.end());

        //O(N+E)
        while(!minHeap.empty()){
            auto it = minHeap.top(); minHeap.pop();
            int curCost = it[0];
            int curNode = it[1];

            //if found
            if(markedNodes.find(curNode) != markedNodes.end()){
                return curCost;
            }

            //traverse through the neighboring nodes
            for(auto& it: graph[curNode]){
                int node = it.first;
                int neighborCost = it.second;
                int newCost = neighborCost + curCost;
                if(newCost < minCost[node]){
                    minCost[node] = newCost;
                    minHeap.push({newCost, node});
                }
            }
        }

        return -1;
    }
};