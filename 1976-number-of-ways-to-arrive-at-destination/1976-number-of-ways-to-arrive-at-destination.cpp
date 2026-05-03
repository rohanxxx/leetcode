class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> graph(n);

        for(auto it: roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }

        vector<int> ways(n, 0);
        vector<long long> cost(n, LLONG_MAX);
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        pq.push({0, 0});
        ways[0] = 1;
        cost[0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long t = it[0];
            int node = it[1];



            for(auto adj: graph[node]){
                int adjn = adj.first;
                int adjt = adj.second;

                long long totalT = (long long)adjt + t;

                if(totalT > cost[adjn]) continue;

                if(totalT < cost[adjn]){
                    pq.push({totalT, adjn});
                    cost[adjn] = totalT;
                    ways[adjn] = ways[node];
                    continue;
                }

                // equal cost — accumulate ways
                ways[adjn] = ((ways[adjn] + ways[node]) % mod);
            }
        }

        return ways[n-1];
    }
};