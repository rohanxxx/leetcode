class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v,w});
        }

        //time, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});

        vector<int> minTime(n+1, INT_MAX);
        minTime[k] = 0;

        while(!pq.empty()){
            int w = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            //now traverse
            for(auto it: graph[u]){
                int newWeight = it.second+w;
                int v = it.first;
                if(newWeight < minTime[v]){
                    pq.push({newWeight, v});
                    minTime[v] = newWeight;
                }
            }
        }

        int minNetworkTime = INT_MIN;
        for(int i = 1; i <= n; i++){
            minNetworkTime = max(minNetworkTime, minTime[i]);
        }

        if(minNetworkTime == INT_MAX){
            return -1;
        }

        return minNetworkTime;
    }
};