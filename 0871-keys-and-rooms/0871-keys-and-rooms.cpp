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

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        //rooms is equavalent to graph
        /*for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(rooms, i, visited);
                break;
            }
        }*/

        visited[0] = true;
        dfs(rooms, 0, visited);

        for(bool v: visited){
            if(!v) return false;
        }
        return true;
    }
};