class Solution {
public:    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[101];
        // Build the adjacency list
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            adj[source].push_back({travelTime, dest});
        }

        vector<int> signalReceivedAt(n + 1, INT_MAX);
        // BFS(signalReceivedAt, k);
        queue<int> q; q.push(k);
        
        signalReceivedAt[k] = 0;
        
        while (!q.empty()) {
            int currNode = q.front(); 
            q.pop();
            
            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int time = edge.first, neighborNode = edge.second;
                int arrivalTime = signalReceivedAt[currNode] + time;
                if (signalReceivedAt[neighborNode] > arrivalTime) {
                    signalReceivedAt[neighborNode] = arrivalTime;
                    q.push(neighborNode);
                }
            }
        }
        
        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, signalReceivedAt[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        if(answer == INT_MAX) return -1;
        return answer;
    }
};