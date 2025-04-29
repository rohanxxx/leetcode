class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for(auto it: prerequisites){
            indegree[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoSort;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topoSort.push_back(node);
            for(int adjNode: graph[node]){
                if(--indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        if(topoSort.size() != n) return {};
        return topoSort;
    }
};