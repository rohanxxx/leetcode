class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[101];
        //build the graph here
        for(auto& t: times){
            int source = t[0];
            int dest = t[1];
            int time = t[2];
            adj[source].push_back({time, dest});
        }

        vector<int> signalAt(n+1, INT_MAX);

        queue<int> q; q.push(k);

        signalAt[k] = 0;

        while(!q.empty()){
            int curNode = q.front(); q.pop();
            for(pair<int, int>edge: adj[curNode]){
                int time = edge.first, neighborNode = edge.second;
                int arrivalTime = signalAt[curNode] + time;
                if(arrivalTime < signalAt[neighborNode]){
                    signalAt[neighborNode] = arrivalTime;
                    q.push(neighborNode);
                } 
            }
        }

        int answer = INT_MIN;
        for(int i = 1; i <= n; i++){
            answer = max(answer, signalAt[i]);
        }

        if(answer == INT_MAX) return -1;

        return answer;
    }
};