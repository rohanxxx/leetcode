class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for(auto it: prerequisites){
            indegree[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }
        
        int count = 0;
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            count++;
            int node = q.front(); q.pop();
            for(int adjNode: graph[node]){
                if(--indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        return count == n;
    }
};