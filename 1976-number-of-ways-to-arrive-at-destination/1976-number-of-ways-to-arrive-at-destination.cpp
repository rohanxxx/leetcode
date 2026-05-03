class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //for mod operation
        int mod = 1e9+7;
        //generate the graph here
        vector<vector<pair<int,int>>> graph(n);
        //O(E)
        for(auto it: roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }

        //O(V)
        vector<int> ways(n, 0);
        vector<long long > cost(n, LLONG_MAX);
        
        //{t, node, parent}
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        pq.push({0,0,-1});
        ways[0] = 1;
        cost[0] = 0;

        //O(V+Elog(V+E))
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long t = it[0];
            int node = it[1];
            int parent = it[2];

            //check the adj list
            for(auto adj: graph[node]){
                int adjn = adj.first;
                int adjt = adj.second;
                //if parent we skip
                /*if(adjn == parent){
                    continue;
                }*/
                long long totalT = (long long)((long long)adjt+t);
                if((long long)totalT > (long long)cost[adjn]){
                    continue;
                }
                if((long long)totalT < (long long)cost[adjn]){
                    pq.push({totalT, adjn, node});
                    //cost and ways get resetted
                    //with new val
                    cost[adjn] = totalT;
                    ways[adjn] = ways[node];
                    
                    continue;
                }

                //if the same exists
                //we just update ways[adjn] += with ways[node]
                ways[adjn] = ((ways[adjn] + ways[node]) % mod);
            }
        }

        return ways[n-1];
    }
};