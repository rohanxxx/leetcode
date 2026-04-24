class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0,0,0});

        vector<vector<int>> minSoFar(n, vector<int>(m, INT_MAX));
        minSoFar[0][0] = 0;

        vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();

            int effort = it[0];
            int r = it[1];
            int c = it[2];

            for(auto cell: dir){
                int adjr = cell.first+r;
                int adjc = cell.second+c;

                if(adjr < 0 || adjr >= n || adjc < 0 || adjc >= m){
                    continue;
                }

                int adjEffort = abs(heights[adjr][adjc]-heights[r][c]);
                int updateMin = max(adjEffort, effort);

                if(updateMin >= minSoFar[adjr][adjc]){
                    continue;
                }

                minHeap.push({updateMin, adjr, adjc});
                minSoFar[adjr][adjc] = updateMin;
            }
            
        }

        return minSoFar[n-1][m-1];
    }
};