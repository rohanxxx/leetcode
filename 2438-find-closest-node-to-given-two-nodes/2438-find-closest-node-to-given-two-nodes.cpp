class Solution {
public:
    void bfs(int node, vector<int>& dis, unordered_map<int, vector<int>>& graph){
        queue<vector<int>> q;
        q.push({0, node});
        dis[node] = 0;
        while(!q.empty()){
            int curDis = q.front()[0];
            int curNode = q.front()[1];
            q.pop();
            for(auto it: graph[curNode]){
                if(curDis+1 < dis[it]){
                    q.push({curDis+1, it});
                    dis[it] = curDis+1;
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                graph[i].push_back(edges[i]);
            }
        }
        vector<int> dis1(n, INT_MAX), dis2(n, INT_MAX);
        bfs(node1, dis1, graph);
        bfs(node2, dis2, graph);
        int minDis = INT_MAX;
        int minDisNode = -1;
        for(int i = 0; i < n; i++){
            if(dis1[i] == INT_MAX || dis2[i] == INT_MAX){
                continue;
            }
            int maxDist = max(dis1[i], dis2[i]);
            if (maxDist < minDis) {
                minDis = maxDist;
                minDisNode = i;
            } else if (maxDist == minDis && i < minDisNode) {
                minDisNode = i;  // break ties by choosing smaller index
            }
        }
        return minDisNode;
    }
};