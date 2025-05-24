/*
       0 1
    0 |0 4
    1 |4 4
*/
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        //{cost, row, col}
        pq.push({0,0,0});

        cost[0][0] = 0;

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!pq.empty()){
            int curCost = pq.top()[0];
            int curRow = pq.top()[1];
            int curCol = pq.top()[2];

            pq.pop();

            if(curRow == n-1 && curCol == m-1){
                return cost[curRow][curCol];
            }

            for(auto it: dir){
                int adjr = curRow + it[0];
                int adjc = curCol + it[1];
                if(adjr >= 0 && adjc >= 0 && adjr < n && adjc < m){
                    int newCost = 0;
                    if(curCost < moveTime[adjr][adjc]){
                        newCost = moveTime[adjr][adjc]+1;
                    }
                    else{
                        newCost = curCost + 1;
                    }
                    if(newCost < cost[adjr][adjc]){
                        cost[adjr][adjc] = newCost;
                        pq.push({newCost, adjr, adjc});
                    }
                }
            }
        }

        return -1;
    }
};