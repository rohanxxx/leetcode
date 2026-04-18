class Solution {
public:
    pair<int, int> bfs(int node, vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> visited(n);
        queue<int> q; 
        
        q.push(node);
        visited[node] = 1;

        int distance = 0;
        int lastNode = node;
        while(!q.empty()){
            distance++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int currNode = q.front(); q.pop();
                lastNode = currNode;
                //traverse the edges
                for(auto adjn: graph[currNode]){
                    if(visited[adjn] == 0){
                        q.push(adjn);
                        visited[adjn] = 1;
                    }
                }
            }
        }

        return {lastNode, distance-1};
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        //build the graph
        vector<vector<int>>graph (n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        pair<int, int> ret;
        ret = bfs(0, graph);
        int farthestNode = ret.first;

        ret = bfs(farthestNode, graph);
        int diameter = ret.second;

        return diameter;
    }
};