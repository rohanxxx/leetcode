class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int node){
        color[node] = 0;
        queue<int> q; q.push(node);
        while(!q.empty()){
            // int parentNodeColor = color[node];
            int curNode = q.front(); q.pop();
            int parentNodeColor = color[curNode];
            for(int nextNode: graph[curNode]){
                if(color[nextNode] == -1){
                    color[nextNode] = !parentNodeColor;
                    q.push(nextNode);
                }
                else if(color[nextNode] == parentNodeColor){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue;
            if(!bfs(graph, color, i)){
                return false;
            }
        }
        return true;
    }
};