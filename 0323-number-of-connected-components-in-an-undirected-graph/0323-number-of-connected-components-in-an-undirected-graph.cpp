class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int countComponents = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                countComponents++;
                q.push({i, -1});
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto adjNode: graph[node]){
                        if(visited[adjNode] == 0){
                            visited[adjNode] = 1;
                            q.push({adjNode, parent});
                        }
                    }
                }
            }
        }
        return countComponents;
    }
};