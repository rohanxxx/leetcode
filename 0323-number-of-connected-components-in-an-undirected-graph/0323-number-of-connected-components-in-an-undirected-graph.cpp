class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited){
        if(!visited[node]){
            visited[node] = true;
            for(int i = 0; i < graph[node].size(); i++){
                dfs(graph, graph[node][i], visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                visited[i] = true;
                
                for(int j = 0; j < graph[i].size(); j++){
                    dfs(graph, graph[i][j], visited);
                }
            }
        }

        return count;
    }
};