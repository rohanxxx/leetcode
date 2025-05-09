/*
                    0 - 1 - 3
                    \   /
                      2
    tin =   0 1 2 3
            0 1 2 3 
    lin =   0 1 0 3
                        0 
*/

class Solution {
public:
    int time = 0;
    vector<vector<int>> ans;

    void dfs(int curNode, int parentNode, vector<int>& tin, vector<int>& lin,  
                    vector<int>& visited, vector<vector<int>>& graph)
    {
        tin[curNode] = lin[curNode] = time;
        visited[curNode] = 1;
        time++;
        for(auto adjNode: graph[curNode]){
            if(adjNode == parentNode) continue;
            
            if(visited[adjNode] == 0){
                dfs(adjNode, curNode, tin, lin, visited, graph);
                lin[curNode] = min(lin[curNode], lin[adjNode]);
                //basically checking critical connections
                if(lin[adjNode] > tin[curNode]){
                    ans.push_back({curNode, adjNode});
                }
            }
            else{
                lin[curNode] = min(lin[curNode], lin[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto edges: connections){
            graph[edges[0]].push_back(edges[1]);
            graph[edges[1]].push_back(edges[0]);
        }

        vector<int> visited(n, 0);
        vector<int> tin(n, 0);
        vector<int> lin(n, 0);
        dfs(0, -1, tin, lin, visited, graph);

        return ans;
    }
};