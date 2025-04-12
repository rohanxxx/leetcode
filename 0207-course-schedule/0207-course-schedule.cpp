class Solution {
public:
    bool dfs(int node, vector<bool>& visited, vector<bool>& inStack, vector<vector<int>>& graph){
        if(inStack[node]) return true;
        if(visited[node]) return false;

        inStack[node] = true;
        visited[node] = true;

        for(int nextNode: graph[node]){
            if(dfs(nextNode, visited, inStack, graph)){
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        int n = numCourses;
        vector<vector<int>> graph(n);
        for(auto prereq: prerequisites){
            graph[prereq[1]].push_back(prereq[0]);
        }
        vector<bool> visited (n, false);
        vector<bool> inStack (n, false);

        for(int i = 0; i < n; i++){
            // if detects cycle return false;
            if(dfs(i, visited, inStack, graph)){
                return false;
            }
        }
        return true;
    }
};