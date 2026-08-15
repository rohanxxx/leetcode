/*
    Input: n = 5, queries = [[2,4],[0,2],[0,4]]
    Output: [3,2,1]

    0 -> 1 -> 2 -> 3 -> 4
*/
class Solution {
public:
    int bfs(int n, vector<vector<int>>& graph){
        vector<int> visited(n+1, false);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.front(); q.pop();
                if(node == n){
                    return level;
                }
                for(auto adjn: graph[node]){
                    if(visited[adjn] == 1){
                        continue;
                    }
                    q.push(adjn);
                    visited[adjn] = 1;
                }
            }
            level++;
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < n-1; i++){
            graph[i].push_back(i+1);
        }

        vector<int> ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
            
            int dist = bfs(n-1, graph);
            ans.push_back(dist);
        }

        return ans;
    }
};