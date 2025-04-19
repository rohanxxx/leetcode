class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        // build the graph here
        for(vector<int> prereq: prerequisites){
            indegree[prereq[0]]++;
            graph[prereq[1]].push_back(prereq[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                // cout << "i: " << i << endl;
                q.push(i);
            }
        }
        // vector<int> topoSort;
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            // topoSort.push_back(node);
            count++;
            for(int nextNode: graph[node]){
                if(--indegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }
        // if(topoSort.size() == n) return true;
        return count == n;
    }
};