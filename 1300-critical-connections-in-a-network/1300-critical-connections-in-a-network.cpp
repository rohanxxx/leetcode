class Solution {
public:
    int time;
    void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& visited, vector<vector<int>>& ccn, vector<int>& tin, vector<int>& lin){
        visited[node] = 1;
        tin[node] = lin[node] = time;

        time++;

        for(int adjNode: graph[node]){
            if(adjNode == parent) continue;
            if(visited[adjNode] == 0){
                dfs(adjNode, node, graph, visited, ccn, tin, lin);
                lin[node] = min(lin[adjNode], lin[node]);
                if(lin[adjNode] > tin[node]){
                    ccn.push_back({node, adjNode});
                }
            }
            else{
                lin[node] = min(lin[adjNode], lin[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto it: connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<vector<int>> ccn;
        vector<int> visited(n, 0);
        vector<int> tin(n, 0);
        vector<int> lin(n, 0);
        
        time = 0;

        dfs(0, -1, graph, visited, ccn, tin, lin);
        
        return ccn;
    }
};