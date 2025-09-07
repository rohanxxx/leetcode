class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        //SC: O(N+E)
        //TC: O(N)
        vector<vector<vector<int>>> graph(n);

        //TC: O(E)
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            int st = it[2];
            int et = it[3];

            graph[u].push_back({v, st, et});
        }

        vector<int> minTime(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        //{curTime, node}
        minHeap.push({0, 0});
        minTime[0] = 0;
        
        //TC: O(LogN*E)
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();

            int curNode = top[1];
            int curTime = top[0];

            if(curNode == n-1){
                return curTime;
            }

            for(auto& it: graph[curNode]){
                int adjNode = it[0];
                int startTime = it[1];
                int endTime = it[2];

                if(curTime > endTime) continue;

                int newTime = max(curTime, startTime)+1;
                if(newTime < minTime[adjNode]){
                    minTime[adjNode] = newTime;
                    minHeap.push({newTime, adjNode});
                }
            }
        }

        return -1;
    }
};