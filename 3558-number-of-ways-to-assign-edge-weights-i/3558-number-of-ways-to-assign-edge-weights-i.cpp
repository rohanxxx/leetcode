/*
    1 -> 2
*/
class Solution {
public:
    int mod = 1e9+7;
    int dfs(int node, int sum, int weight, unordered_map<int, int>& parent, vector<vector<int>>& dp){
        if(node == 1){
            if(sum % 2 == 1){
                return 1;
            }
            return 0;
        }
        if(dp[node][weight] != -1){
            return dp[node][weight];
        }

        int count = 0;
        for(int i = 1; i <= 2; i++){
            count = (count + (dfs(parent[node], i+sum, i, parent, dp)%mod))%mod;
        }

        return dp[node][weight] = (count%mod);
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //SC:O(V+E)
        int n = edges.size()+1;
        unordered_map<int, int> parent;
        unordered_map<int, vector<int>> graph;
        vector<int> visited(n+1, 0);
        //TC: O(V+E)
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        //we need to find the depth
        queue<vector<int>> q; q.push({1, 0});
        parent[1] = 0;
        visited[1] = 1;
        int lastNode = -1;
        while(!q.empty()){
            int node = q.front()[0];
            int parentNode = q.front()[1];

            q.pop();

            //saving the most last node
            //basically the max depth node
            lastNode = node;

            //traverse through children nodes
            for(auto adjNode: graph[node]){
                if(adjNode == parentNode || visited[adjNode] == 1){
                    continue;
                }
                q.push({adjNode, node});
                visited[adjNode] = 1; 

                parent[adjNode] = node;
            }
        }
        //SC: O(V*3)
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return dfs(lastNode, 0, 0, parent, dp);
    }
};