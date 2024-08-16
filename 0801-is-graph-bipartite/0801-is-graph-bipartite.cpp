class Solution {
private:
    bool bfs(vector<vector<int>>& graph, vector<int>& color,int node){
        queue<int> q; q.push(node);
        color[node] = 0;
        
        while(!q.empty()){
            int parentNode = q.front();
            int parentNodeColor = color[parentNode];
            q.pop();
            
            for(auto nextNode: graph[parentNode]){
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

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};