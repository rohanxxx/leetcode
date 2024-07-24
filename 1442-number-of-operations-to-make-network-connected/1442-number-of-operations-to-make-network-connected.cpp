class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto& connection: connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numOfConnectedComponents = 0;
        vector<bool> visited(n);
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                numOfConnectedComponents++;
                dfs(i, adj, visited);
            }
        }

        return numOfConnectedComponents-1;

    }
};