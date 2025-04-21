class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = INT_MAX;
            }
        }

        //{u, v, weight}
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            graph[u][v] = weight;
            graph[v][u] = weight;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    //it means do not make any changes otherwise do the operation
                    if(i == j || graph[i][via] == INT_MAX || graph[via][j] == INT_MAX){
                        continue;
                    }
                    graph[i][j] = min(graph[i][j], graph[i][via]+graph[via][j]);
                }
            }
        }
        
        int minCount = INT_MAX, ans;
        vector<int> reachable(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(graph[i][j] <= distanceThreshold) reachable[i]++;
            }
            if(reachable[i] <= minCount){
                minCount = reachable[i];
                ans = i;
            }
        }
        
        return ans;
    }
};