class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited){
        for(int i = 0; i < graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                visited[graph[node][i]] = true;
                dfs(graph, graph[node][i], visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        //first build the graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]) graph[i].push_back(j);
            }
        }

        int provinces = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                provinces++;
                dfs(graph, i, visited);
            }
        }

        return provinces;
    }
};