class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adjList(n);
        for(auto& prereq: prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //build the prerequisite
        vector<unordered_set<int>> prereqs(n);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto& adj: adjList[node]){
                prereqs[adj].insert(node);
                //getting all the prereqs
                for(auto& prereq: prereqs[node]){
                    prereqs[adj].insert(prereq);
                }

                if(--indegree[adj] == 0){
                    q.push(adj);
                }
            }
        }

        vector<bool> ans;
        for(auto& query: queries){
            int u = query[0];
            int v = query[1];
            //if found
            if(prereqs[v].find(u) != prereqs[v].end()){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};