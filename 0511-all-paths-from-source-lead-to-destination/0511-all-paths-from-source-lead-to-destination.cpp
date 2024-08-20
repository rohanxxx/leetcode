class Solution {
public:
    bool dfs(int curNode, int target, vector<vector<int>>& graph,  vector<int>& color){
        if(graph[curNode].empty()) return curNode == target;
        
        color[curNode] = 0;

        for(auto& neighbor: graph[curNode]){
            if(color[neighbor] == 0) return false;
            if(color[neighbor] == -1){
                if(!dfs(neighbor, target, graph, color)) return false;
            }
        }

        color[curNode] = 1;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        //build the graph
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> color(n, -1);

        return dfs(source, destination, graph, color);
    }
};