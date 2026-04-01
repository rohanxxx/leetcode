class Solution {
public:
/*
    [0,0],[2,2],[3,10],[5,2],[7,0]
    0       1       2   3       4
    0->1 0->2 ....0->n-1 to our minheap data structure {distance, index}
    manhattan distance formula would be Manhattan Distance = abs(x1-x2)+abs(y1-y2)

*/
    //TC: O(N*NLogN)
    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalCost = 0;
        int n = points.size();
        //Overall SC = O(N+N) = O(2N) = O(N)
        //SC: O(N)
        vector<int> visited(n,0);
        //minheap
        //SC: O(N)
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>, 
                            greater<pair<int, int>>> pq;
        pq.push({0, 0});
        //TC: O(N*N*logN)
        //O(N)
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node] == 0){
                totalCost += dis;
            }
            else{
                continue;
            }

            visited[node] = 1;

            //O(N)
            for(int i = 0; i < n; i++){
                if(visited[i] == 0){
                    int adjr = points[i][0];
                    int adjc = points[i][1];
                    int curR = points[node][0];
                    int curC = points[node][1];
                    int manDis = abs(curR-adjr)+abs(curC-adjc);
                    //O(LogN)
                    pq.push({manDis, i});
                }
            }
        }
        return totalCost;
    }
};