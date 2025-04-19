class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto prereq: prerequisites){
            indegree[prereq[0]]++;
            graph[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoSort;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topoSort.push_back(node);
            for(int nextNode: graph[node]){
                if(--indegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }
        if((int)topoSort.size() == n) return topoSort;
        return {};
    }
};