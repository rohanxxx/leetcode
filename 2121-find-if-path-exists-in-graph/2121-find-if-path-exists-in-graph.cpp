class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& seen, int currNode, int& dest){
        if(currNode == dest) return true;
        if(seen[currNode] == false){
            seen[currNode] = true;
            for(auto& nextNode: graph[currNode]){
                if(dfs(graph, seen, nextNode, dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> seen(n);
        return dfs(graph, seen, source, destination);
    }
};