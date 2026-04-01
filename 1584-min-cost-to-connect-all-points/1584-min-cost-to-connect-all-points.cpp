class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> visited(n, 0);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,-1});

        int totalMinDis = 0;
        while(!pq.empty()){
            int dis = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];

            pq.pop();

            if(visited[node] == 1){
                continue;
            }

            totalMinDis += dis;
            visited[node] = 1;

            int r = points[node][0];
            int c = points[node][1];
            for(int i = 0; i < n; i++){
                if(parent == i || visited[i] == 1){
                    continue;
                }
                int adjr = points[i][0];
                int adjc = points[i][1];
                int manDis = abs(r-adjr) + abs(c-adjc);
                pq.push({manDis, i, node});
            }
        }

        return totalMinDis;
    }
};