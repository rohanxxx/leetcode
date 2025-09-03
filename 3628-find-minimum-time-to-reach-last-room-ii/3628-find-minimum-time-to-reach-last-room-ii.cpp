class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        //const int INF = INT_MAX / 4;
        // dist[r][c][parity]
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

        // {cost, parity, r, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        dist[0][0][0] = 0;
        minHeap.push({0, 0, 0, 0});

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!minHeap.empty()){
            auto it = minHeap.top(); minHeap.pop();

            int curCost = it[0];
            int check   = it[1]; // parity of NEXT move
            int r       = it[2];
            int c       = it[3];

            if(r == n-1 && c == m-1){
                return curCost;
            }

            for(auto& d: dir){
                int adjr = r + d[0];
                int adjc = c + d[1];

                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    int newCost = max(moveTime[adjr][adjc], curCost) + 1;
                    if(check) newCost++;
                    if(newCost < dist[adjr][adjc][!check]){
                        dist[adjr][adjc][!check] = newCost;
                        minHeap.push({newCost, !check, adjr, adjc});
                    }
                }
            }
        }

        return -1;
    }
};