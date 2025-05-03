class Solution {
public:
/*
    a is dependent on b. in order to take course a we should always take course b first
    indegree vector:    0 1
                        0 1
    BFS 
    first we would push the indegree's that has 0 dependencies
    queue: 0
    once we pop the queue and get 0 we mark it visited then we go to the outdegree node which we 
    traverse 
    like this 
    for(i->adjList){
        before we push it to queue 
        we are going to decrease 1 by 1 and then if it is 0 the indegree then we push it to the queue
    }
*/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegrees(n, 0);
        //build the graph
        vector<vector<int>> graph(n);
        for(auto it: prerequisites){
            graph[it[1]].push_back(it[0]);
            indegrees[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegrees[i] == 0) q.push(i);
        }

        while(!q.empty()){
            n--;
            int node = q.front(); q.pop();
            for(auto adjNode: graph[node]){
                if(--indegrees[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        return n==0;
    }
};