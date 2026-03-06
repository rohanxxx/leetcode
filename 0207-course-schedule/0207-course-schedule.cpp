class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites){
            int v = it[0];
            int u = it[1];
            indegree[v]++;
            graph[u].push_back(v);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i); 
        }

        int count = 0;
        while(!q.empty()){
            count++;
            int v = q.front(); q.pop();
            for(auto adjn: graph[v]){
                indegree[adjn]--;
                if(indegree[adjn] == 0){
                    q.push(adjn);
                }
            }
        }

        if(count == numCourses) return true;
        else return false;
    }
};