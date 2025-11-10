class Solution {
public:
    vector<char> seen; // visited for dfs

    // dfs now walks predecessor map (parent, edgeIdx) and marks edges
    void dfs(int node, vector<bool>& ans, vector<vector<pair<int,int>>>& map){
        if (seen[node]) return;
        seen[node] = true;
        if (node == 0) return;

        for (auto &prev : map[node]) {
            int p = prev.first;
            int edgeIdx = prev.second;
            ans[edgeIdx] = true;      // mark this edge as used by some shortest path
            dfs(p, ans, map);
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        // Build graph with edge indices
        int m = (int)edges.size();
        vector<vector<tuple<int,int,int>>> graph(n); // (neighbor, weight, edgeIdx)
        for (int i = 0; i < m; ++i) {
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            graph[a].push_back({b, w, i});
            graph[b].push_back({a, w, i});
        }

        // predecessor map: for each node, vector of (parentNode, edgeIndex)
        vector<vector<pair<int,int>>> map(n);

        // Dijkstra (long long)
        const long long INF = (long long)4e18;
        vector<long long> minWeight(n, INF);

        using T = tuple<long long,int,int>; // (cost, node, parent)
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0LL, 0, -1});
        minWeight[0] = 0LL;

        while(!pq.empty()){
            auto [cost, node, parent] = pq.top(); pq.pop();
            if (cost != minWeight[node]) continue; // skip stale

            for (auto &[adjn, adjCost, ei] : graph[node]){
                long long totalCost = cost + (long long)adjCost;

                // IMPORTANT: do NOT skip (adjn == parent); equal-cost alt paths may come through
                if(totalCost <= minWeight[adjn]){
                    if(totalCost < minWeight[adjn]){
                        minWeight[adjn] = totalCost;
                        map[adjn].clear();          // new best: reset predecessors
                    }
                    map[adjn].push_back({node, ei}); // keep this parent via edge idx
                    pq.push({totalCost, adjn, node});
                }
            }
        }

        // per-EDGE answers
        vector<bool> ans(m, false);

        // no path? return all false
        if (minWeight[n-1] == INF) return ans;

        // DFS back from target to mark all edges on any shortest path
        seen.assign(n, 0);
        dfs(n-1, ans, map);

        return ans;
    }
};