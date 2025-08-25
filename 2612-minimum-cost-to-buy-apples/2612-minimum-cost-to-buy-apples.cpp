class Solution {
public:
    int shorttestPath(int& city, int& n, int& k, vector<int>& appleCost, vector<vector<pair<int, int>>>& graph){
        vector<int> dist(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ;

        //{cost, city}
        minQ.push({0, city});

        long long minCost = INT_MAX;
        while(!minQ.empty()){
            auto current = minQ.top(); minQ.pop();
            int cost = current[0];
            int curCity = current[1];

            minCost = min(minCost, (long long)cost * (k+1) + appleCost[curCity]);

            for(auto& it: graph[curCity]){
                int nextCost = it.second + cost;
                int neighbor = it.first;
                if(nextCost < dist[neighbor]){
                    dist[neighbor] = nextCost;
                    minQ.push({nextCost, neighbor});
                }
            }
        }

        if(minCost == INT_MAX) return -1;
        return minCost;
    }
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(auto& it: roads){
            graph[it[0]-1].push_back({it[1]-1, it[2]});
            graph[it[1]-1].push_back({it[0]-1, it[2]});
        }

        vector<long long> ans(n, 0);
        for(int startCity = 0; startCity < n; startCity++){
            ans[startCity] = shorttestPath(startCity, n, k, appleCost, graph);
        }

        return ans;
    }
};