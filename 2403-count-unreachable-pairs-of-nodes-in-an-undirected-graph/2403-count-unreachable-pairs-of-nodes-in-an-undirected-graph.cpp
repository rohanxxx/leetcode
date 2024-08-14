class Solution {
public:
    int dfs( vector<vector<int>>& graph, int node, vector<bool>& visited){
        int count = 1;
        visited[node] = true;
        
        for(int nextNode: graph[node]){
            if(!visited[nextNode]){
                count += dfs(graph, nextNode, visited);
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        //build the graph
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long numberOfNodes = 0;
        long long unreachablePairs = 0;
        long long remainingNodes = n;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                numberOfNodes = dfs(graph, i, visited);
                unreachablePairs += numberOfNodes * (remainingNodes - numberOfNodes);
                remainingNodes -= numberOfNodes;
            }
        }
        return unreachablePairs;
    }
};