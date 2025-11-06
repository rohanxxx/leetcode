class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // store up to two arrival times for each node
        vector<vector<int>> cost(n + 1);
        vector<int> cost2(n + 1, -1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 1, -1});
        cost[1].push_back(0);

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int curTime = it[0];
            int curNode = it[1];
            int parent = it[2];

            // reached destination with 2nd arrival
            if ((int)cost[n].size() == 2 && curNode == n) return cost[n][1];

            for (auto adjNode : graph[curNode]) {
                // ✅ don't skip revisits; second path might require them
                long long depart = curTime;
                long long period = depart / change;
                if (period % 2 == 1) depart += (change - (depart % change)); // wait to next green
                long long newTime = depart + time;

                // ✅ record up to 2 distinct times per node
                if (cost[adjNode].empty() || (cost[adjNode].size() == 1 && cost[adjNode][0] != newTime)) {
                    cost[adjNode].push_back((int)newTime);
                    pq.push({(int)newTime, adjNode, curNode});
                    sort(cost[adjNode].begin(), cost[adjNode].end());
                    if (cost[adjNode].size() > 2) cost[adjNode].pop_back();
                    if (cost[adjNode].size() == 2) cost2[adjNode] = cost[adjNode][1];
                }
            }
        }

        return cost2[n];
    }
};