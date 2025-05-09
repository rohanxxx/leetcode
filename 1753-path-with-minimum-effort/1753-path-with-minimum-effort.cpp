/*
    arr[r*c] = which includes all the heights of each cell
    I start from 0,0 end and r-1, c-1
    i can go left, righ, up and down
    looking for routes that requires minimum effort
    effort = maximum absolute value difference in the heights between two consecutive cells of the route
    return the minimum affort required to travel from start to dest.

    [1,2,2]
    [3,8,2]
    [5,3,5]

    Output: 2

    {maxEffort, r, c}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();         //row size
        int m = heights[0].size();      //col size
        
        //if(n == 1 && m == 1) return 0;

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); effort[0][0] = 0;

        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
        while(!pq.empty()){
            int minEffortSoFar = pq.top()[0];
            int curRow = pq.top()[1];
            int curCol = pq.top()[2];

            pq.pop();
            //chcek if we reached out destination
            if(curRow == n-1 && curCol == m-1){
                //to do later
                return minEffortSoFar;
            }

            for(auto d: dir){
                int adjr = curRow + d[0];
                int adjc = curCol + d[1];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    int curEffort = abs(heights[adjr][adjc]-heights[curRow][curCol]);
                    int newMinEffort = max(curEffort, minEffortSoFar);
                    if(newMinEffort < effort[adjr][adjc]){
                        effort[adjr][adjc] = newMinEffort;
                        pq.push({newMinEffort, adjr, adjc});
                    }
                }
            }
        }

        return 0;
    }
};