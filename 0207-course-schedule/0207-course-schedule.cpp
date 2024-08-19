class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inStack){
        //detects cycle
        if(inStack[node]) return true;
        if(visited[node]) return false;

        visited[node] = true;
        inStack[node] = true;

        for(int neighbor: graph[node]){
            if(dfs(neighbor, graph, visited, inStack)) return true;
        }

        inStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& prereq: prerequisites){
            graph[prereq[1]].push_back(prereq[0]);
        }

        vector<bool> visited(numCourses);
        vector<bool> inStack(numCourses);

        for(int i = 0; i < numCourses; i++){
            if(dfs(i, graph, visited, inStack)){
                return false;
            }
        }

        return true;
    }
};